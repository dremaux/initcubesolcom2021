#pragma once

#include "Lib.h"
#include "DispatcheurMeasure.hpp"
#include "Status.hpp"
#include "DispatcheurMission.hpp"

using namespace std;

class DispatcheurReponse {

public:
    DispatcheurReponse();
    void setTrame(string trame){this->trame = trame;}
    string identifierType();
    string genererTrame();
    ~DispatcheurReponse();

private:
    string trame;
    DispatcheurMeasure* measure; 
    Status* status;
    DispatcheurMission* mission;
};