#include "Simple.hpp"

Simple::Simple() {

}

void Simple::extraireDonner(char* trame, int nbOctetType, string unite){
    caseFinM = trame[2] + 2;
    caseDebutM = DEBUT_TRAME + nbOctetType;
    donneeExtraite = "";
    for(int i = caseDebutM+1; i <= caseFinM;i++){ //le +1 est la pour ignorer le premier espace 
        if(trame[i] == ' '){
            donneeExtraite = donneeExtraite + unite + " ";
        }
        else{
            donneeExtraite = donneeExtraite + trame[i];
        }
    }
}

string Simple::genererTrame(string nom, string type, string unite){
    json trame;
    trame["instrument"]["name"] = nom;
    trame["instrument"]["type mesure"] = type;
    trame["instrument"]["donnée"] = donneeExtraite + unite;
    return trame.dump();
    
}

Simple::~Simple() {

}