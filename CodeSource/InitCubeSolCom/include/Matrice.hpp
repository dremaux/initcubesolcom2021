#pragma once
#include "Measure.hpp"
#define DEBUT_TRAME 12

class Matrice : public Measure{

public:
    Matrice();
    ~Matrice();
    void extraireDonnee(unsigned char* trame, int nbOctetType);
    std::string genererTrame(std::string nom, std::string typeMeasure, std::string type, std::string dt = "");

private:
    bool security;
    int compteur;
};