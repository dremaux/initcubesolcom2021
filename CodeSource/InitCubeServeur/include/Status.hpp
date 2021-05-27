#pragma once
#include "Lib.h"
#define NBRE_TRAMES 8
#define NUM_TRAME 9

using namespace std;

class Status {

public:
    Status();
    void extraireDonnee(string trame);
    string genereTrame();
    ~Status();

private:
    int caseFinP;
    int finChamp;
    bool security;
    int compteur;
    bool bord;
    string SMo;
    string Rp;
    string Tbord;
    string DTb;
    bool batt;
    string C;
    string V;
    string A;
    bool load;
    string Tbatt;
    bool inst;
    string marche;
    bool erreur;
    string modeExp;
    string dureeSTBY;
    string Tinst;
    bool cube;
    string Tcube;
    bool reboot;
    string DTr;
    string N;
};