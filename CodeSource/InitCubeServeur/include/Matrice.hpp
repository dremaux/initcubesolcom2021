#pragma 
#include "Lib.h"
#define NBRE_TRAMES 9
#define NUM_TRAME 10
#define DEBUT_TRAME 16

using namespace std;
using json = nlohmann::json;

class Matrice {

public:
    Matrice();
    ~Matrice();
    void extraireDonnee(char* trame);
    string genereTrame();

private:
    string donneeExtraite;
    int caseFinM;
    int caseDebutM;
    int compteur = 1;
};