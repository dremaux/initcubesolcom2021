#include "SimpleMission.hpp"

SimpleMission::SimpleMission()
{
}

void SimpleMission::extraireDonnee(unsigned char *trame, int nbOctetType)
{
    caseFinM = trame[1] + 2;
    caseDebutM = DEBUT_TRAME + nbOctetType;
    std::string donnee = "";
    while (!donneeExtraite.empty())
    {
        donneeExtraite.erase(donneeExtraite.begin());
    }

    for (int i = caseDebutM + 1; i <= caseFinM; i++)
    { //le +1 est la pour ignorer le premier espace
        if (trame[i] == '-' && trame[i + 1] == 'T')
        {
            i += 2; //on passe les cases -T
            for (int y = 0; y < 4; y++)
            {
                donnee += trame[i];
                i++; //on passe les cases extraites
            }
            donneeExtraite.push_back(donnee);
            donnee = "";
        }
        else if (trame[i] == '-' && trame[i + 1] == 'D' && trame[i + 2] == 'T')
        {
            i += 3; //on passe les cases -DT
            for (int y = 0; y < 19; y++)
            {
                donnee += trame[i];
                i++; //on passe les cases extraites
            }
            dateExtraite.push_back(donnee);
            donnee = "";
        }
    }
}

std::string SimpleMission::genererTrame(std::string nom, std::string type, std::string unite, std::string dt)
{
    json trame;
    trame["mission"]["type"] = nom;
    trame["mission"]["code"] = type;
    if (donneeExtraite.size() == dateExtraite.size())
    {
        for (int i = 0; i < dateExtraite.size(); i++)
        {
            trame["mission"]["donnees"][i]["donnee"] = donneeExtraite[i];
            trame["mission"]["donnees"][i]["date"] = dateExtraite[i];
        }
    }
    else
    {
        cout << "erreur trame reponse mission nombre date != nombre donnee" << endl;
        return 0;
    }

    trame["mission"]["unite"] = unite;
    if (dt != "")
    {
        trame["mission"]["date"] = dt;
    }

    return trame.dump();
}

SimpleMission::~SimpleMission()
{
}