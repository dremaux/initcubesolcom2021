#include "Measure.hpp"

Measure::Measure(){

}

Measure::Measure(string trame):trame(trame) {

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
                    simple->extraireDonner((char*)trame.c_str(),type.length());
                    reponse = simple->genererTrame(instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["NOM"],instrument["INITCUBE"]["INSTRUMENT"][i]["TYPEMEASURE"]["UNITE"]);
                    return reponse;
                }
                if(typeMesure == "matrice"){
                    matrice->extraireDonnee((char*)trame.c_str(),type.length());
                    reponse = matrice->genereTrame();
                    return reponse;
                }
                if(typeMesure == "image"){
                    cout<<"appel methode image"<<endl;
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