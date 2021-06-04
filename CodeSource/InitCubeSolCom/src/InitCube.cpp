#include "InitCube.hpp"

InitCube::InitCube()
{
    numMap = 0;
    serveurEcouteJTP = new ServeurTransmitionCommande(9951);   //json to protocol
    serveurEcriturePTJ = new ServeurReceptionTelemesure(9950); //protocol to json
    commande = new Commande();
    reponse = new DispatcheurReponse();
    mtxCommande = serveurEcouteJTP->getMutex();
    comInitCube = new ComInitCube("/dev/ttyAMA0", 9600);
    mtxTelemesure = new mutex();
}

InitCube::~InitCube()
{
    delete serveurEcouteJTP;
    delete serveurEcriturePTJ;
    delete commande;
    delete reponse;
    delete mtxTelemesure;
    delete mtxCommande;
    delete comInitCube;
}

void InitCube::attenteAbonnement()
{
    while (1)
    {
        serveurEcriturePTJ->attendreConnexion();
    }
}

void InitCube::transmitionCommande()
{
    while (1)
    {
        numMap = serveurEcouteJTP->attendreConnexion();
        if (numMap >= 0)
        {
            nouveauClient();
        }
    }
}

void InitCube::envoieVol()
{
    unsigned char trameF[110];
    while (1)
    {
        if (!serveurEcouteJTP->getRecu().empty())
        {
            for (int i = 0; i < 110; i++)
            {
                trameF[i] = 0;
            }
            mtxCommande->lock();
            bool set = commande->setTrame(serveurEcouteJTP->getRecu().front());
            serveurEcouteJTP->effacerPremierRecu();
            mtxCommande->unlock();
            if (set && commande->extraireDonnees() > 0)
            {
                bool com = commande->genererTrame(trameF); //remplacer cout par la liaison serie

                if (com)
                {
                    comInitCube->transmettreTrame(trameF);
                }
            }
        }
    }
}

void InitCube::receptionVol()
{
    unsigned char recu[110];
    vector<unsigned char> v;
    while (1)
    {
        if (!v.empty())
        {
            for (int i = 0; i < v.size(); i++)
            {
                v.erase(v.begin());
            }
        }
        bool lire = comInitCube->lireTrame(recu, 110);
        if (lire)
        {
            mtxTelemesure->lock();
            for (int i = 0; i < 110; i++)
            {

                v.push_back(recu[i]);
            }
            telemesure.push(v);
            mtxTelemesure->unlock();
        }
        else
        {
            cout << "erreur cks" << endl;
        }
    }
}

void InitCube::envoieTelemesure()
{
    while (!telemesure.empty())
    {
        unsigned char trame[110];
        for (int i = 0; i < 110; i++)
        {
            trame[i] = 0;
        }
        mtxTelemesure->lock();
        for (int i = 0; i < telemesure.front().size(); i++)
        {
            trame[i] = telemesure.front()[i];
        }
        telemesure.pop();
        mtxTelemesure->unlock();

        reponse->setTrame(trame);

        string recuR = reponse->identifierType();
        if (recuR == "JSON")
        {
            string trameG = reponse->genererTrame();
            if (trameG != "")
            {
                char trameGC[trameG.size() + 1];
                for (int i = 0; i < trameG.size() + 1; i++)
                {
                    trameGC[i] = trameG[i];
                }
                serveurEcriturePTJ->transmettre(trameGC, trameG.size());
            }
        }
    }
}

thread InitCube::member1Thread()
{
    return thread([=]
                  {
                      int numMapC = numMap;
                      int retour = 0;
                      while (retour >= 0)
                      {
                          retour = serveurEcouteJTP->attendreCommande(numMapC);
                      }
                  });
}

void InitCube::nouveauClient()
{

    thread *monThreadClient = new thread(member1Thread());
    //monThreadClient.detach();
}