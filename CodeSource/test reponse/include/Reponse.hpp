#pragma once

#include "Lib.h"
#include "Measure.hpp"
#include "Status.hpp"
#include "Mission.hpp"

using namespace std;

class Reponse {

public:
    Reponse();
    void setTrame(string trame){this->trame = trame;}
    string identifierType();
    string genererTrame();
    ~Reponse();

private:
    string trame;
    Measure* measure; 
    Status* status;
    Mission* mission;
};