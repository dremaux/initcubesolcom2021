#pragma once

#include "Lib.h"
#include "DispatcheurMeasure.hpp"
#include "Status.hpp"
#include "DispatcheurMission.hpp"

using namespace std;

class DispatcheurReponse {

public:
    DispatcheurReponse();
    void setTrame(char* trame);
    string identifierType();
    string genererTrame();
    ~DispatcheurReponse();

private:
    char* trame;
    DispatcheurMeasure* measure; 
    Status* status;
    DispatcheurMission* mission;
};