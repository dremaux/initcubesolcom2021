#pragma once
#include "Measure.hpp"
#define DEBUT_TRAME_IMAGE 14
#define NB_PIXEL_IMAGE 320*240*3
#define NBRE_SECTION 11
#define NUM_SECTION 12

class Image : public Measure{

public:
    Image();
    void extraireDonnee(unsigned char* trame, int nbOctetType);
    bool genererImage(std::string nom, int width, int height);
    std::string genererTrame(std::string nom, std::string typeMeasure, std::string type, std::string dt = "");
    ~Image();
    
    

private:
    char donneeExtraite[NB_PIXEL_IMAGE];
    int height;
    int width;
    std::string name;
};