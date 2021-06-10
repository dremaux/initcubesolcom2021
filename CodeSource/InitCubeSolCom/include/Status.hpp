#pragma once
#include "Lib.h"
#define NBRE_TRAMES 8
#define NUM_TRAME 9

using namespace std;
using json = nlohmann::json;

class Status {

public:
    Status();
    void extraireDonnee(std::string trame);
    std::string genereTrame();
    ~Status();

private:
    int caseFinP;
    int finChamp;
    bool security;
    int compteur;
    bool bord;
    std::string SMo;
    std::string Rp;
    std::string Tbord;
    std::string DTb;
    bool batt;
    std::string C;
    std::string V;
    std::string A;
    bool load;
    std::string Tbatt;
    bool inst;
    std::string marche;
    bool erreur;
    std::string modeExp;
    std::string dureeSTBY;
    std::string Tinst;
    bool cube;
    std::string Tcube;
    bool reboot;
    std::string DTr;
    std::string N;
};