#include "Matrice.hpp"

Matrice::Matrice() {
    security = false;
    compteur = 1;
}

Matrice::~Matrice() {

}

void Matrice::extraireDonnee(char* trame, int nbOctetType){
    if(trame[NUM_TRAME] == compteur){
        security = false;
        caseFinM = trame[2] + 3;
        caseDebutM = DEBUT_TRAME + nbOctetType;
        if(trame[NUM_TRAME] == 1){
            donneeExtraite = "";
        }
    
        if(trame[NBRE_TRAMES] == trame[NUM_TRAME]){
            compteur = 1;//reset du compteur
            for(int i = caseDebutM+1; i < caseFinM;i++){ //le +1 est la pour ignorer le premier espace 
                if(trame[i]== ' '){
                    donneeExtraite = donneeExtraite + ',';
                }
                else{
                    donneeExtraite = donneeExtraite + trame[i];
                }
            }
        }
        else{
            compteur ++;
            for(int i = caseDebutM+1; i <= caseFinM;i++){ //le +1 est la pour ignorer le premier espace 
                if(trame[i]== ' '){
                    donneeExtraite = donneeExtraite + ',';
                }
                else{
                    donneeExtraite = donneeExtraite + trame[i];
                }
            }
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

string Matrice::genereTrame(string nom){
    json trame;
    if(compteur == 1 && security == false){
        trame["instrument"][nom] = donneeExtraite;
        return trame.dump();
    }
    else{
        cout<<"trame precedente pas fini"<<endl;
        return "";
        
    }
}   