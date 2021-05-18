#pragma once
#include "Lib.h"
#include "Matrice.hpp"
#include "Simple.hpp"
#include "Image.hpp"

using namespace std;
using json = nlohmann::json;

class DispatcheurMeasure {

public:
    DispatcheurMeasure();
    DispatcheurMeasure(string trame);
    void identifierType();
    void setTrame(string trame);
    string genererTrame();
    ~DispatcheurMeasure();

private:
    string reponse;
    string trame;
    string type;
    Matrice* matrice;
    Simple* simple;
    Image* image;
};