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
    DispatcheurMeasure(unsigned char* trame);
    virtual void identifierType();
    void setTrame(unsigned char* trame);
    virtual string genererTrame();
    virtual ~DispatcheurMeasure();

protected:
    string reponse;
    unsigned char* trame;
    string type;
    Measure *matrice , *simple, *image;
};