#pragma once
#include "Lib.h"
#include "toojpeg.h"
#define NBRE_TRAMES 10
#define NUM_TRAME 11
#define DEBUT_TRAME 16
#define TAILLE_IMAGE 320*240
#define NBRE_SECTION 12
#define NUM_SECTION 13

using namespace std;
using json = nlohmann::json;

class Image {

public:
    Image();
    void extraireDonnee(char* trame, int nbOctetType);
    bool genereImage();
    string genereTrame(string nom);
    ~Image();
    string getName(){ return name;}
    void setName(string nom);
    void setAberation(bool oui){ aberation = oui;}
    
    

private:
    bool security;
    char donneeExtraite[TAILLE_IMAGE];
    int caseFinM;
    int caseDebutM;
    int compteurT;
    int compteurS;
    int iterateur;
    string name;
    bool aberation;
};