#pragma once
#include "Lib.h"
#define NBRE_TRAMES 10
#define NUM_TRAME 11
#define DEBUT_TRAME 13

using namespace std;
using json = nlohmann::json;

class Matrice {

public:
    Matrice();
    ~Matrice();
    void extraireDonnee(char* trame, int nbOctetType);
    string genereTrame(string nom);

private:
    bool security;
    string donneeExtraite;
    int caseFinM;
    int caseDebutM;
    int compteur;
};