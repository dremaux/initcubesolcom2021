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
    virtual void extraireDonnee(unsigned char* trame, int nbOctetType) = 0;
    virtual std::string genererTrame(std::string nom, std::string type, std::string unite, std::string dt = "") = 0;

protected:
    
    vector<std::string> donneeExtraite;
    int caseFinM;
    int caseDebutM;

};