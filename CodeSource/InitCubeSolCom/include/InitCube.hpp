#pragma once
#include "ServeurReceptionTelemesure.hpp"
#include "ServeurTransmitionCommande.hpp"
#include "Commande.hpp"
#include "DispatcheurReponse.hpp"
#include "ComInitCube.h"
#include <thread>
#include "Lib.h"
#include "GestionCommandes.h"

using namespace std;

class InitCube
{

public:
    InitCube();
    void attenteAbonnement();
    void transmitionCommande();
    void envoieVol();
    void receptionVol();
    void envoieTelemesure();
    ~InitCube();

private:
    thread member1Thread();
    void nouveauClient();
    int numMap;
    queue<vector<unsigned char>> telemesure;
    mutex *mtxCommande;
    mutex *mtxTelemesure;
    ServeurTransmitionCommande *serveurEcouteJTP;
    ServeurReceptionTelemesure *serveurEcriturePTJ;
    Commande *commande;
    DispatcheurReponse *reponse;
    ComInitCube *comInitCube;
    GestionCommandes *gestionCommandes;
};