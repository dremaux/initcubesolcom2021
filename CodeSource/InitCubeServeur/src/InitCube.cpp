#include "InitCube.hpp"

InitCube::InitCube()
{
    numMap = 0;
    securite = true;
    lecture = false;
    ecriture = false;
    serveurEcouteJTP = new ServeurTransmitionCommande(9951);   //json to protocol
    serveurEcriturePTJ = new ServeurReceptionTelemesure(9950); //protocol to json
    commande = new Commande();
    reponse = new DispatcheurReponse();
    mtxSerie = new mutex();
    mtxCommande = serveurEcouteJTP->getMutex();
}

InitCube::~InitCube()
{
    delete serveurEcouteJTP;
    delete serveurEcriturePTJ;
    delete commande;
    delete reponse;
    delete mtxSerie;
}

void InitCube::reseptionTelemesure()
{
    while (1)
    {
        numMap = serveurEcouteJTP->attendreConnexion();
        if (numMap >= 0)
        {
            thread *monThreadClient = new thread(nouveauClient);
        }
    }
}

void InitCube::transmitionCommande()
{
    while (1)
    {
        serveurEcriturePTJ->attendreConnexion();
    }
}

void InitCube::nouveauClient()
{
    int numMapC = numMap;
    int retour = 0;
    while (retour >= 0)
    {
        retour = serveurEcouteJTP->attendreCommande(numMapC);
        if (retour >= 0)
        {
            ecriture = true;
            cv.notify_all();
            ecriture = false;
        }
    }
}

void InitCube::envoieVol()
{
    unique_lock<mutex> lck(*mtxSerie);
    while (1)
    {
        while (!ecriture)
            cv.wait(lck);
        mtxCommande->lock();
        bool set = commande->setTrame(serveurEcouteJTP->getRecu().front());
        serveurEcouteJTP->effacerPremierRecu();
        mtxCommande->unlock();
        if (set && commande->extraireDonnees() > 0)
        {
            lecture = false;
            while (securite)
                ;
            cout << commande->genererTrame() << endl; //remplacer cout par la liaison serie
            lecture = true;
            cv.notify_all();
        }
    }
}

void InitCube::receptionVol()
{
    unsigned char recu[1];
    unique_lock<mutex> lck(*mtxSerie);
    while (1)
    {
        while (!lecture)
            cv.wait(lck);
        securite = true;
        if (/*liaison serie > */ 0)
        {
            recu[0] = 'l'; //liaison serie
            reponse->setTrame(recu);
            string recuR = reponse->identifierType();
            if (recuR == "JSON")
            {
                string trameG = reponse->genererTrame();
                if (recu[10] == recu[11])
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
        securite = false;
    }
}
