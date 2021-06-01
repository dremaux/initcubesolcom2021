#pragma once
#include "Measure.hpp"
#define DEBUT_TRAME 12

class Simple : public Measure {

public:
    Simple();
    void extraireDonnee(unsigned char* trame, int nbOctetType);
    string genererTrame(string nom, string type, string unite, string dt = "");
    ~Simple();
};