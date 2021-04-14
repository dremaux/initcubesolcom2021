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
        int debut = trame.find('-')+1;//+1 pour ignorer le -
        int fin = trame.find(' ');
        type = trame.substr(debut,(fin - debut));
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
                {"DESCRIPTION":{},"ETAT":{},"TYPEMEASURE":{"NOM":"matrice","ID":"PIX","TYPE":"matrice"}}
            ]
        }
    })"_json;
    if(instrument.find("INITCUBE") != instrument.end() && instrument["INITCUBE"].find("INSTRUMENT") != instrument["INITCUBE"].end()){
        for(int i = 0;i<instrument["INITCUBE"]["INSTRUMENT"].size();i++){
            string id = instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["ID"];//si on ne stock pas le resultat et que on le test directement il retourne des ""
            if(type == id){
                string typeMesure = instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["TYPE"];
                if(typeMesure == "simple"){
                    simple->extraireDonner(trameC,type.length());
                    reponse = simple->genererTrame(instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["NOM"],instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["UNITE"]);
                    return reponse;
                }
                if(typeMesure == "matrice"){
                    matrice->extraireDonnee(trameC,type.length());
                    if(trame[NBRE_TRAMES] == trame[NUM_TRAME]){
                        reponse = matrice->genereTrame(instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["NOM"]);
                        return reponse;
                    }
                    
                }
                if(typeMesure == "image"){
                    image->extraireDonnee(trameC,type.length());
                    if(trame[NBRE_TRAMES] == trame[NUM_TRAME] && trame[NBRE_SECTION] == trame[NUM_SECTION]){
                        time_t now = time(0);
                        string dt = ctime(&now);
                        image->setName(dt);
                        reponse = image->genereTrame(instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["NOM"]);
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

}