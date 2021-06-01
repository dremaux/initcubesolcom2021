#pragma once
#include "Lib.h"
#include "Simple.hpp"

class SimpleMission : public Simple{

public:
    SimpleMission();
    void extraireDonnee(unsigned char* trame, int nbOctetType);
    string genererTrame(string nom, string type, string unite, string dt = "");
    ~SimpleMission();
private:
    vector<string> dateExtraite;
};