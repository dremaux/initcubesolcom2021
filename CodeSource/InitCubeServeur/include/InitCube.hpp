#pragma once
#include "ServeurReceptionTelemesure.hpp"
#include "ServeurTransmitionCommande.hpp"
#include "Commande.hpp"
#include "DispatcheurReponse.hpp"
#include <thread>
#include "Lib.h"

using namespace std;

class InitCube
{

public:
    InitCube();
    void reseptionTelemesure();
    void transmitionCommande();
    void envoieVol();
    void receptionVol();
    ~InitCube();

private:
    void nouveauClient();
    int numMap;
    bool securite;
    bool lecture;
    bool ecriture;
    mutex *mtxCommande;
    mutex *mtxSerie;
    condition_variable cv;
    ServeurTransmitionCommande *serveurEcouteJTP;
    ServeurReceptionTelemesure *serveurEcriturePTJ;
    Commande *commande;
    DispatcheurReponse *reponse;
};