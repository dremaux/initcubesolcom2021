#include "Matrice.hpp"

Matrice::Matrice() {
    
}

Matrice::~Matrice() {

}

void Matrice::extraireDonnee(char* trame){
    if(trame[NUM_TRAME] == compteur){
        caseFinM = trame[2] + 1;
        caseDebutM = 16;
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
        perror("tramme precedente non complete");
        if(trame[NUM_TRAME]==1){
            compteur = 1;
            extraireDonnee(trame);
        }
    }
}