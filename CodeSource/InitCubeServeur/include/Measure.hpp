#pragma once
#include "Lib.h"
#include "Matrice.hpp"

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
    string trame = "";
    string type = "";
    Matrice* matrice = new Matrice();
};