#pragma once
#include "Lib.h"
#include "Matrice.hpp"
#include "Simple.hpp"
#include "Image.hpp"
#define NBRE_TRAMES 10
#define NUM_TRAME 11
#define NBRE_SECTION 12
#define NUM_SECTION 13

using namespace std;
using json = nlohmann::json;

class Measure {

public:
    Measure();
    Measure(string trame);
    void identifierType();
    void setTrame(string trame);
    string genererTrame();
    ~Measure();

private:
    string reponse;
    string trame;
    string type;
    Matrice* matrice;
    Simple* simple;
    Image* image;
};