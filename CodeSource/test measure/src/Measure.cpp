#include "Measure.hpp"

Measure::Measure(){
    reponse = "";
    trame = "";
    type = "";
    matrice = new Matrice();
    simple = new Simple();
    image = new Image();
}

Measure::Measure(string trame):trame(trame) {
    reponse = "";
    trame = "";
    type = "";
    matrice = new Matrice();
    simple = new Simple();
    image = new Image();
}

void Measure::identifierType(){
    if(trame.find("MEASURE") > 0 ){
        if(trame[11] == '-' || trame[11] == ' '){
            int debut = trame.find('-',12)+1;//+1 pour ignorer le - et 12 pour ignorer la premiere occurene qui est a 11
            int fin = trame.find(' ',13);
            type = trame.substr(debut,(fin - debut));
        }
        else{
            int debut = trame.find('-')+1;//+1 pour ignorer le -
            int fin = trame.find(' ');
            type = trame.substr(debut,(fin - debut));
        }
    }
    else{
        perror("ce n'est pas une trame measure");
    }
}

void Measure::setTrame(string trame){
    this->trame = trame;
}

string Measure::genererTrame(){
    char* trameC = (char*)trame.c_str();
    json instrument;
    instrument =R"({
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
    if(instrument.find("INITCUBE") != instrument.end() && instrument["INITCUBE"].find("INSTRUMENT") != instrument["INITCUBE"].end()){
        for(int i = 0;i<instrument["INITCUBE"]["INSTRUMENT"].size();i++){
            string id = instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["ID"];//si on ne stock pas le resultat et que on le test directement il retourne des ""
            if(type == id){
                string typeMesure = instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["TYPE"];
                if(typeMesure == "simple"){
                    simple->extraireDonner(trameC,type.length(),instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["UNITE"]);
                    reponse = simple->genererTrame(instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["NOM"], instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["ID"], instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["UNITE"]);
                    return reponse;
                }
                if(typeMesure == "matrice"){
                    matrice->extraireDonnee(trameC,type.length());
                    if(trame[NBRE_TRAMES] == trame[NUM_TRAME]){
                        reponse = matrice->genereTrame(instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["NOM"], instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["ID"]);
                        return reponse;
                    }
                    
                }
                if(typeMesure == "image"){
                    unsigned char trameUC[trame.length()];
                    for(int i = 0;i<trame.length();i++){//on convertie en unsigned char car les pixels peuvent prendre une valeure plus haute que 127 et pas de valeur negative
                        trameUC[i] = trameC[i];
                    }
                    image->extraireDonnee(trameUC,type.length());
                    if(trame[NBRE_LIGNES] == trame[NUM_LIGNE] && trame[NBRE_SECTION] == trame[NUM_SECTION]){
                        time_t now = time(0);
                        string dt = ctime(&now);
                        dt.erase(dt.length()-1,1);//supprime le \n de fin
                        image->genereImage(dt,instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["WIDTH"], instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["HEIGHT"]);
                        reponse = image->genereTrame(instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["NOM"], instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["ID"]);
                        return reponse;
                    }
                }
            }
        }
    }
    else{
        cout<<"trame non conforme"<<endl;
    }
    return "";

}

Measure::~Measure() {
    delete matrice;
    delete image;
    delete simple;
}