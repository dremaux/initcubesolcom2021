#include "Matrice.hpp"

Matrice::Matrice() {
    
}

Matrice::~Matrice() {

}

void Matrice::extraireDonnee(char* trame){
    if(trame[NUM_TRAME] == compteur){
        caseFinM = trame[2] + 1;
        caseDebutM = DEBUT_TRAME;
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
        if(trame[NUM_TRAME]==1){
            cout<<"debut nouvelle trame abandon de la precedente"<<endl;
            compteur = 1;
            extraireDonnee(trame);
        }
    }
}

string Matrice::genereTrame(){
    json trame;
    if(compteur = 1){
        trame["instrument"]["matrice"] = donneeExtraite;
        return trame.dump();
    }
    else{
        cout<<"trame precedente non complete"<<endl;
    }
}   