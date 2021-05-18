#include "Simple.hpp"

Simple::Simple()
{
}

void Simple::extraireDonner(char *trame, int nbOctetType)
{
    caseFinM = trame[2] + 2;
    caseDebutM = DEBUT_TRAME + nbOctetType;
    string donnee;
    for (int i = 0; i < donneeExtraite.size(); i++)
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
            donnee = donnee + trame[i];
        }
    }
}

string Simple::genererTrame(string nom, string type, string unite)
{
    json trame;
    trame["measure"]["name"] = nom;
    trame["measure"]["code"] = type;
    trame["measure"]["donnee"] = donneeExtraite;
    trame["measure"]["unite"] = unite;
    return trame.dump();
}

Simple::~Simple()
{
}