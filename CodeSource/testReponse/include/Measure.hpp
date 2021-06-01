#pragma once
#include "Lib.h"
#define NBRE_TRAMES 9
#define NUM_TRAME 10

using namespace std;
using json = nlohmann::json;

class Measure {

public:
    Measure();
    virtual ~Measure();
    virtual void extraireDonnee(char* trame, int nbOctetType) = 0;
    virtual string genererTrame(string nom, string type, string unite, string dt = "") = 0;

protected:
    
    vector<string> donneeExtraite;
    int caseFinM;
    int caseDebutM;

};