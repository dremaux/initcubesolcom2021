#pragma once
#define TAILLEBUFFER 2000

#include "Lib.h"

using namespace std;

class Serveur {

public:
    Serveur(int port);
    virtual ~Serveur();
    int attendreConnexion();

protected:
    struct sockaddr_in ecoute;  //Structure de la socket
    int canal;  //canal de la socket du serveur
    int sockAccept; //canal de la socket venant de se connecter au serveur
    vector <int> connexionsV; //collection des canaux connectés au serveur 
    map <int,int> connexionsM; //collection des canaux connectés au serveur 
    int iterateur;

};