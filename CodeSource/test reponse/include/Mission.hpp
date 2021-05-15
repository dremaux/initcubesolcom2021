#pragma once
#include "Lib.h"
#include "Matrice.hpp"
#include "Image.hpp"
#include "Simple.hpp"

using namespace std;

class Mission {

public:
    Mission();
    ~Mission();
    void setTrame(string trame){this->trame = trame;}
    string identifierType();
    string genererTrame();

private:
    string reponse;
    string trame;
    string type;
    Matrice* matrice;
    Simple* simple;
    Image* image;

};