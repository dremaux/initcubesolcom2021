#pragma once
#include "Lib.h"
#include "toojpeg.h"
#define NBRE_LIGNES 10
#define NUM_LIGNE 11
#define DEBUT_TRAME_IMAGE 15
#define NB_PIXEL_IMAGE 320*240*3
#define NBRE_SECTION 12
#define NUM_SECTION 13

using namespace std;
using json = nlohmann::json;

class Image {

public:
    Image();
    void extraireDonnee(unsigned char* trame, int nbOctetType);
    bool genereImage(string nom);
    string genereTrame(string nom, string type);
    ~Image();
    
    

private:
    bool security;
    unsigned char donneeExtraite[NB_PIXEL_IMAGE];
    int caseFinM;
    int caseDebutM;
    int compteurT;
    int compteurS;
    int iterateur;
    int height;
    int width;
    string name;
};