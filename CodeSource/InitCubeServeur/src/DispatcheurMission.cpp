#include "DispatcheurMission.hpp"

DispatcheurMission::DispatcheurMission()
{
    simple = new SimpleMission();
}

string DispatcheurMission::genererTrame()
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
                    if (trame[NBRE_TRAMES] == trame[NUM_TRAME])
                    {
                        string date = "";
                        for (int h = (trame[1] + 2) - 18; h < ((trame[1] + 2) - 18) + 19; h++)
                        {
                            date += trame[h];
                        }
                        trame[1] -= 22;
                        matrice->extraireDonnee(trame, type.length());
                        reponse = matrice->genererTrame(instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["NOM"], instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["ID"], "mission", date);
                        return reponse;
                    }
                    matrice->extraireDonnee(trame, type.length());
                }
                if (typeMesure == "image")
                {
                    string date = "";
                    for (int h = (trame[1] + 2) - 18; h < ((trame[1] + 2) - 18) + 19; h++)
                    {
                        date += trame[h];
                    }
                    trame[1] -= 22;
                    time_t now = time(0);
                    string dt = ctime(&now);
                    dt.erase(dt.length() - 1, 1); //supprime le \n de fin
                    image->extraireDonnee(trame, type.length());
                    ((Image *)image)->genererImage(dt, instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["WIDTH"], instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["HEIGHT"]);
                    reponse = image->genererTrame(instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["NOM"], instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["ID"], "mission", date);
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

DispatcheurMission::~DispatcheurMission()
{
    delete image;
    delete matrice;
    delete simple;
}