#pragma once
#include "Lib.h"
#include "Simple.hpp"

class SimpleMission {

public:
    SimpleMission();
    void extraireDonner(char* trame, int nbOctetType);
    string genererTrame(string nom, string type, string unite);
    ~SimpleMission();
private:
    vector<string> dateExtraite;
    vector<string> donneeExtraite;
    int caseFinM;
    int caseDebutM;
};