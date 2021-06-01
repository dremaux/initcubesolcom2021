#pragma once
#include "Measure.hpp"
#define DEBUT_TRAME 12

class Matrice : public Measure{

public:
    Matrice();
    ~Matrice();
    void extraireDonnee(char* trame, int nbOctetType);
    string genererTrame(string nom, string typeMeasure, string type, string dt = "");

private:
    bool security;
    int compteur;
};