#pragma once
#include "Lib.h"
#include "Matrice.hpp"
#include "Image.hpp"
#include "SimpleMission.hpp"

using namespace std;

class Mission {

public:
    Mission();
    ~Mission();
    void setTrame(string trame){this->trame = trame;}
    void identifierType();
    string genererTrame();

private:
    string reponse;
    string trame;
    string type;
    Matrice* matrice;
    SimpleMission* simple;
    Image* image;

};