#include "Simple.hpp"

Simple::Simple()
{
}

void Simple::extraireDonnee(unsigned char *trame, int nbOctetType)
{
    caseFinM = trame[1] + 2;
    caseDebutM = DEBUT_TRAME + nbOctetType;
    std::string donnee;
    while (!donneeExtraite.empty())
    {
        donneeExtraite.erase(donneeExtraite.begin());
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
}

std::string Simple::genererTrame(std::string nom, std::string type, std::string unite, std::string dt)
{
    json trame;
    trame["mesure"]["type"] = nom;
    trame["mesure"]["code"] = type;
    trame["mesure"]["donnees"] = donneeExtraite;
    trame["mesure"]["unite"] = unite;
    if (dt != "")
    {
        trame["mesure"]["date"] = dt;
    }

    return trame.dump();
}

Simple::~Simple()
{
}