#pragma once
#include "Lib.h"
#include "Matrice.hpp"
#include "Simple.hpp"
#include "Image.hpp"
#include "GestionConfiguration.h"

using namespace std;
using json = nlohmann::json;

class DispatcheurMeasure {

public:
    DispatcheurMeasure();
    DispatcheurMeasure(unsigned char* trame);
    virtual void identifierType();
    void setTrame(unsigned char* trame);
    virtual std::string genererTrame();
    virtual ~DispatcheurMeasure();

protected:
    std::string reponse;
    unsigned char* trame;
    std::string type;
    Measure *matrice , *simple, *image;
    GestionConfiguration *gestionConfiguration;
};