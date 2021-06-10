#include "DispatcheurMission.hpp"

DispatcheurMission::DispatcheurMission()
{
    simple = new SimpleMission();
}

std::string DispatcheurMission::genererTrame()
{
    json instrument;
    instrument = R"({"ConfInstru":[
	{
		"nom":"Camera infrarouge",
		"identifiant":"123BCD",
		"ref":"Matrice",
		"adresse":"",
		"role":"mesurer une temperature",
		"listeTypesMesure":[
			{
				"nom":"temperature",
				"type":"normal",
				"code":"TC",
				"description":"Température de l'objet mesuré",
				"unite":"°C",
				"valMax":"+90",
				"valMin":"-40"
			},
			{
				"nom":"matrice",
				"type":"matrice",
				"code":"PIX",
				"description":"Matrice d'une température de l'objet mesuré",
				"unite":"°C",
				"valMax":"+90",
				"valMin":"-40"
			}
		]
	},
    {
        "nom":"Camera photo",
        "identifiant":"",
        "ref":"",
        "adresse":"",
        "role":"prendre des photos",
        "listeTypesMesure":[
            {
                "nom":"photo",
                "type":"image",
                "code":"IMG",
                "description":"",
                "unite":"",
                "hauteur":240,
                "largeur":320

            }
        ]
    },
	{
		"nom":"Magnétomètre",
		"identifiant":"124BCD",
		"ref":"Magnetometre",
		"adresse":"",
		"role":"Mesurer un champ magnétique",
		"listeTypesMesure":[
			{
				"nom":"BX",
				"type":"normal",
				"code":"BX",
				"description":"Champ magnetique suivant X ",
				"unite":"μT",
				"valMax":"+100",
				"valMin":"0"
			},
			{
				"nom":"BY",
				"type":"normal",
				"code":"BY",
				"description":"Champ magnetique suivant Y ",
				"unite":"μT",
				"valMax":"+100",
				"valMin":"0"
			},
			{
				"nom":"BZ",
                "type":"normal",
				"code":"BZ",
				"description":"Champ magnetique suivant Z ",
				"unite":"μT",
				"valMax":"+100",
				"valMin":"0"
			}
		]
	}
    ]})"_json;
    for (int p = 0; p < instrument["ConfInstru"].size(); p++)
    {
        for (int i = 0; i < instrument["ConfInstru"][p]["listeTypesMesure"].size(); i++)
        {
            std::string id = instrument["ConfInstru"][p]["listeTypesMesure"][i]["code"]; //si on ne stock pas le resultat et que on le test directement il retourne des ""
            if (type == id)
            {
                std::string typeMesure = instrument["ConfInstru"][p]["listeTypesMesure"][i]["type"];
                if (typeMesure == "normal")
                {
                    simple->extraireDonnee(trame, type.length());
                    if (trame[NBRE_TRAMES] == trame[NUM_TRAME])
                    {
                        reponse = simple->genererTrame(instrument["ConfInstru"][p]["listeTypesMesure"][i]["type"], instrument["ConfInstru"][p]["listeTypesMesure"][i]["code"], instrument["ConfInstru"][p]["listeTypesMesure"][i]["unite"]);
                        return reponse;
                    }
                }
                if (typeMesure == "matrice")
                {
                    if (trame[NBRE_TRAMES] == trame[NUM_TRAME])
                    {
                        std::string date = "";
                        for (int h = (trame[1] + 2) - 18; h < ((trame[1] + 2) - 18) + 19; h++)
                        {
                            date += trame[h];
                        }
                        trame[1] -= 22;
                        matrice->extraireDonnee(trame, type.length());
                        reponse = matrice->genererTrame(instrument["ConfInstru"][p]["listeTypesMesure"][i]["type"], instrument["ConfInstru"][p]["listeTypesMesure"][i]["code"], "mission", date);
                        return reponse;
                    }
                    matrice->extraireDonnee(trame, type.length());
                }
                if (typeMesure == "image")
                {
                    std::string date = "";
                    for (int h = (trame[1] + 2) - 19; h < ((trame[1] + 2) - 19) + 19; h++)
                    {
                        date += trame[h];
                    }
                    time_t now = time(0);
                    std::string dt = ctime(&now);
                    dt.erase(dt.length() - 1, 1); //supprime le \n de fin
                    image->extraireDonnee(trame, type.length());
                    ((Image *)image)->genererImage(dt, instrument["ConfInstru"][p]["listeTypesMesure"][i]["largeur"], instrument["ConfInstru"][p]["listeTypesMesure"][i]["hauteur"]); // attention si hauteur et largeur sont en std::string dans le json ça ne marche pas
                    reponse = image->genererTrame(instrument["ConfInstru"][p]["listeTypesMesure"][i]["type"], instrument["ConfInstru"][p]["listeTypesMesure"][i]["code"], "mission", date);
                    return reponse;
                }
            }
        }
    }
    return "";
}

DispatcheurMission::~DispatcheurMission()
{
}