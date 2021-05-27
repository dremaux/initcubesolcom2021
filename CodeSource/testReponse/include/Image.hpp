#pragma once
#include "Measure.hpp"
#define DEBUT_TRAME_IMAGE 14
#define NB_PIXEL_IMAGE 320*240*3
#define NBRE_SECTION 11
#define NUM_SECTION 12

class Image : public Measure{

public:
    Image();
    void extraireDonnee(char* trame, int nbOctetType);
    bool genererImage(string nom, int width, int height);
    string genererTrame(string nom, string typeMeasure, string type, string dt = "");
    ~Image();
    
    

private:
    char donneeExtraite[NB_PIXEL_IMAGE];
    int height;
    int width;
    string name;
};