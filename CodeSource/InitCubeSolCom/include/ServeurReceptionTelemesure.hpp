#pragma once
#include "Serveur.hpp"

class ServeurReceptionTelemesure : public Serveur {

public:
    ServeurReceptionTelemesure(int port);
    ~ServeurReceptionTelemesure();
    void transmettre(char* message,int taille);
};