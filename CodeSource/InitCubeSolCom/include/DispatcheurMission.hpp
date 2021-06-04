#pragma once
#include "DispatcheurMeasure.hpp"
#include "SimpleMission.hpp"

class DispatcheurMission :public DispatcheurMeasure {

public:
    DispatcheurMission();
    ~DispatcheurMission();
    string genererTrame();


};