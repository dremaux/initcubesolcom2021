#include "DispatcheurMeasure.hpp"

DispatcheurMeasure::DispatcheurMeasure()
{
    reponse = "";
    type = "";
    matrice = new Matrice();
    simple = new Simple();
    image = new Image();
    gestionConfiguration = new GestionConfiguration();//a developer quand la configuration dans la base de donne sera prete
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

std::string DispatcheurMeasure::genererTrame()
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
                    matrice->extraireDonnee(trame, type.length());
                    if (trame[NBRE_TRAMES] == trame[NUM_TRAME])
                    {
                        reponse = matrice->genererTrame(instrument["ConfInstru"][p]["listeTypesMesure"][i]["type"], instrument["ConfInstru"][p]["listeTypesMesure"][i]["code"], "mesure");
                        return reponse;
                    }
                }
                if (typeMesure == "image")
                {
                    image->extraireDonnee(trame, type.length());
                    time_t now = time(0);
                    std::string dt = ctime(&now);
                    dt.erase(dt.length() - 1, 1);                                                                                                                                     //supprime le \n de fin
                    ((Image *)image)->genererImage(dt, instrument["ConfInstru"][p]["listeTypesMesure"][i]["largeur"], instrument["ConfInstru"][p]["listeTypesMesure"][i]["hauteur"]); // attention si hauteur et largeur sont en std::string dans le json ça ne marche pas
                    reponse = image->genererTrame(instrument["ConfInstru"][p]["listeTypesMesure"][i]["type"], instrument["ConfInstru"][p]["listeTypesMesure"][i]["code"], "mesure");
                    return reponse;
                }
            }
        }
    }

    return "";
}

DispatcheurMeasure::~DispatcheurMeasure()
{
    delete matrice;
    delete image;
    delete simple;
}