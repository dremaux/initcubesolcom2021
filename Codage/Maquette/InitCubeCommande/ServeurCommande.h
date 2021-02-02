/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServeurCommande.h
 * Author: snir2g2
 *
 * Created on 5 mars 2020, 13:39
 */

#include "Lib.h"
#ifndef SERVEURCOMMANDE_H
#define SERVEURCOMMANDE_H

using namespace std;

class ServeurCommande {
public:
    ServeurCommande();
    virtual ~ServeurCommande();
    void attendreConnexion();
    void recevoir(char* message,int taille);
private:
    struct sockaddr_in ecoute;  //Structure de la socket
    int canal;  //canal de la socket du serveur
    int sockAccept; //canal de la socket venant de se connecter au serveur
    vector <int>connexions; //collection des canaux connectés au serveur
};

#endif /* SERVEURCOMMANDE_H */

