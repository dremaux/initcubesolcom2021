#include "DispatcheurMeasure.hpp"

DispatcheurMeasure::DispatcheurMeasure()
{
    reponse = "";
    type = "";
    matrice = new Matrice();
    simple = new Simple();
    image = new Image();
}

DispatcheurMeasure::DispatcheurMeasure(unsigned char *trame) : trame(trame)
{
    reponse = "";
    type = "";
    matrice = new Matrice();
    simple = new Simple();
    image = new Image();
}

void DispatcheurMeasure::identifierType()
{
    type = "";
    for (int y = 3; y < 100; y++)
    {
        if (trame[y] == '-')
        {
            y++;
            while (trame[y] != ' ')
            {
                type += trame[y];
                y++;
            }
            return;
        }
    }
}

void DispatcheurMeasure::setTrame(unsigned char *trame)
{
    this->trame = trame;
}

string DispatcheurMeasure::genererTrame()
{
    json instrument;
    instrument = R"({
        "INITCUBE": {
            "DESCRIPTION": {},
            "TRAME": {},
            "ETAT": {},
            "INSTRUMENT": [
                {"DESCRIPTION":{},"ETAT":{},"TYPEMEASURE":{"NOM":"temperature","ID":"TC","TYPE":"simple","UNITE": "°C"}},
                {"DESCRIPTION":{},"ETAT":{},"TYPEMEASURE":{"NOM":"matrice","ID":"PIX","TYPE":"matrice"}},
                {"DESCRIPTION":{},"ETAT":{},"TYPEMEASURE":{"NOM":"image","ID":"IMG","TYPE":"image", "WIDTH": 320, "HEIGHT": 240}}


            ]
        }
    })"_json;
    if (instrument.find("INITCUBE") != instrument.end() && instrument["INITCUBE"].find("INSTRUMENT") != instrument["INITCUBE"].end())
    {
        for (int i = 0; i < instrument["INITCUBE"]["INSTRUMENT"].size(); i++)
        {
            string id = instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["ID"]; //si on ne stock pas le resultat et que on le test directement il retourne des ""
            if (type == id)
            {
                string typeMesure = instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["TYPE"];
                if (typeMesure == "simple")
                {
                    simple->extraireDonnee(trame, type.length());
                    if (trame[NBRE_TRAMES] == trame[NUM_TRAME])
                    {
                        reponse = simple->genererTrame(instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["NOM"], instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["ID"], instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["UNITE"]);
                        return reponse;
                    }
                }
                if (typeMesure == "matrice")
                {
                    matrice->extraireDonnee(trame, type.length());
                    if (trame[NBRE_TRAMES] == trame[NUM_TRAME])
                    {
                        reponse = matrice->genererTrame(instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["NOM"], instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["ID"], "measure");
                        return reponse;
                    }
                }
                if (typeMesure == "image")
                {
                    image->extraireDonnee(trame, type.length());
                    time_t now = time(0);
                    string dt = ctime(&now);
                    dt.erase(dt.length() - 1, 1); //supprime le \n de fin
                    ((Image *)image)->genererImage(dt, instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["WIDTH"], instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["HEIGHT"]);
                    reponse = image->genererTrame(instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["NOM"], instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["ID"], "measure");
                    return reponse;
                }
            }
        }
    }
    else
    {
        cout << "trame non conforme" << endl;
    }
    return "";
}

DispatcheurMeasure::~DispatcheurMeasure()
{
    delete matrice;
    delete image;
    delete simple;
}