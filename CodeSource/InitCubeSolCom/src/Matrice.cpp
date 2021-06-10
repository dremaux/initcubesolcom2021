#include "Matrice.hpp"

Matrice::Matrice()
{
    security = true;
    compteur = 1;
}

Matrice::~Matrice()
{
}

void Matrice::extraireDonnee(unsigned char *trame, int nbOctetType)
{
    if (trame[NUM_TRAME] == compteur)
    {
        security = false;
        caseFinM = trame[1] + 2;
        caseDebutM = DEBUT_TRAME + nbOctetType;
        std::string donnee;
        if (trame[NUM_TRAME] == 1)
        {
            while (!donneeExtraite.empty())
            {
                donneeExtraite.erase(donneeExtraite.begin());
            }
        }

        for (int i = caseDebutM + 1; i <= caseFinM; i++)
        { //le +1 est la pour ignorer le premier espace
            if (trame[i] == ' ')
            {
                donneeExtraite.push_back(donnee);
                donnee = "";
            }
            else
            {
                donnee += trame[i];
            }
        }
        if (trame[NBRE_TRAMES] == trame[NUM_TRAME])
        {
            compteur = 1; //reset du compteur
        }
        else
        {
            compteur++;
        }
    }
    else
    {
        cout << "trame precedente non complete" << endl;
        security = true;
        if (trame[NUM_TRAME] == 1)
        {
            cout << "debut nouvelle trame abandon de la precedente" << endl;
            compteur = 1;
            extraireDonnee(trame, nbOctetType);
        }
    }
}

std::string Matrice::genererTrame(std::string nom, std::string typeMeasure, std::string type, std::string dt)
{
    json trame;
    if (compteur == 1 && security == false)
    {
        trame[type]["type"] = nom;
        trame[type]["code"] = typeMeasure;
        trame[type]["matrice"] = donneeExtraite;
        if (type == "mission")
        {
            trame[type]["date"] = dt;
        }
        return trame.dump();
    }
    else
    {
        cout << "trame precedente pas fini" << endl;
        return "";
    }
}