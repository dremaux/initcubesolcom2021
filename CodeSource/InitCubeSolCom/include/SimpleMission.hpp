#pragma once
#include "Lib.h"
#include "Simple.hpp"

class SimpleMission : public Simple{

public:
    SimpleMission();
    void extraireDonnee(unsigned char* trame, int nbOctetType);
    std::string genererTrame(std::string nom, std::string type, std::string unite, std::string dt = "");
    ~SimpleMission();
private:
    vector<std::string> dateExtraite;
};