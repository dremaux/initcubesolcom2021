#pragma 
#include "Lib.h"

using namespace std;

class Matrice {

public:
    Matrice();
    ~Matrice();
    void extraireDonnee(char* trame);
    string getDonneeExtraite(){return donneeExtraite;};

private:
    bool trameComplete = true;
    string donneeExtraite;
    int caseFinM;
    int caseDebutM;
};