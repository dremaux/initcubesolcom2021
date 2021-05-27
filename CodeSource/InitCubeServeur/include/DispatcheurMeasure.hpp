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
    DispatcheurMeasure(char* trame);
    virtual void identifierType();
    void setTrame(char* trame);
    virtual string genererTrame();
    virtual ~DispatcheurMeasure();

protected:
    string reponse;
    char* trame;
    string type;
    Measure *matrice , *simple, *image;
};