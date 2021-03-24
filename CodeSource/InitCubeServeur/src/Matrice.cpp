#include "Matrice.hpp"

Matrice::Matrice() {
    
}

Matrice::~Matrice() {

}

void Matrice::extraireDonnee(char* trame){
    if(trame[10] != 1 || trameComplete == true){
        trameComplete = false;
        caseFinM = trame[2] + 1;
        caseDebutM = 16;
        if(trame[10] == 1){
            donneeExtraite = "";
        }
    
        if(trame[9] == trame[10]){
            trameComplete = true;
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
    }
}