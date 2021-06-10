#pragma once
#include "Measure.hpp"
#define DEBUT_TRAME 12

class Simple : public Measure {

public:
    Simple();
    void extraireDonnee(unsigned char* trame, int nbOctetType);
    std::string genererTrame(std::string nom, std::string type, std::string unite, std::string dt = "");
    ~Simple();
};