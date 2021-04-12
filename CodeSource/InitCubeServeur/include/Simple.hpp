#pragma once
#include "Lib.h"
#define NBRE_TRAMES 9
#define NUM_TRAME 10
#define DEBUT_TRAME 13

using namespace std;
using json = nlohmann::json;

class Simple {

public:
    Simple();
    void extraireDonner(char* trame, int nbOctetType);
    string genererTrame(string nom,string unite);
    ~Simple();
private:
    string donneeExtraite;
    int caseFinM;
    int caseDebutM;
};