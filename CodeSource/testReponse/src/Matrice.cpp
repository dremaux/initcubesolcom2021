#include "Matrice.hpp"

Matrice::Matrice() {
    security = true;
    compteur = 1;
}

Matrice::~Matrice() {

}

void Matrice::extraireDonnee(char* trame, int nbOctetType){
    if(trame[NUM_TRAME] == compteur){
        security = false;
        caseFinM = trame[2] + 2;
        caseDebutM = DEBUT_TRAME + nbOctetType;
        string donnee;
        if(trame[NUM_TRAME] == 1){
            for(int i = 0;i < donneeExtraite.size();i++){
                donneeExtraite.erase(donneeExtraite.begin());
            }
        }

        for(int i = caseDebutM+1; i <= caseFinM;i++){ //le +1 est la pour ignorer le premier espace 
                if(trame[i]== ' '){
                    donneeExtraite.push_back(donnee);
                    donnee = "";
                }
                else{
                    donnee = donnee + trame[i];
                }
        }
        if(trame[NBRE_TRAMES] == trame[NUM_TRAME]){
            compteur = 1;//reset du compteur
        }
        else{
            compteur ++;
        }
    }else{
        cout<<"trame precedente non complete"<<endl;
        security = true;
        if(trame[NUM_TRAME]==1){
            cout<<"debut nouvelle trame abandon de la precedente"<<endl;
            compteur = 1;
            extraireDonnee(trame,nbOctetType);
        }
    }
}

string Matrice::genereTrame(string nom, string typeMeasure, string type, string dt){
    json trame;
    if(compteur == 1 && security == false){
        trame[type]["name"] = nom;
        trame[type]["typeMesure"] = typeMeasure;
        trame[type]["matrice"] = donneeExtraite;
        if(type == "mission"){
            trame[type]["date"] = dt;
        }
        return trame.dump();
    }
    else{
        cout<<"trame precedente pas fini"<<endl;
        return "";
        
    }
}   