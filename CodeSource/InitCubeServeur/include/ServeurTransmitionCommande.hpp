#pragma once
#include "Serveur.hpp"

class ServeurTransmitionCommande: public Serveur {

public:
    ServeurTransmitionCommande(int port);
    ~ServeurTransmitionCommande();
    int attendreCommande(int fd);
    vector <string> getRecu();
    void effacerPremierRecu();
    mutex* getMutex();

private:
    vector <string> recu; //collection de commande reçu
    mutex* mtx;
};