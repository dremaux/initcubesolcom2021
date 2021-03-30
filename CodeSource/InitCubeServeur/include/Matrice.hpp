#pragma 
#include "Lib.h"
#define NBRE_TRAMES 9
#define NUM_TRAME 10

using namespace std;

class Matrice {

public:
    Matrice();
    ~Matrice();
    void extraireDonnee(char* trame);
    string getDonneeExtraite(){return donneeExtraite;};

private:
    string donneeExtraite;
    int caseFinM;
    int caseDebutM;
    int compteur = 1;
};