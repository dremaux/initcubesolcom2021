/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InitCubeServeur.h
 * Author: snir2g1
 *
 * Created on 28 mars 2019, 10:34
 */

#ifndef INITCUBESERVEUR_H
#define INITCUBESERVEUR_H

#include "Lib.h"

using namespace std;

class InitCubeServeur {
  public:
    InitCubeServeur();
    virtual ~InitCubeServeur();
    void multiClient();
    void attendreConnexion();
    void transmettre(char* message,int taille);
    string genFakeInstrumentFrame();
	string genFakeStateFrame();

  private:
    struct sockaddr_in ecoute;  //Structure de la socket
    int canal;  //canal de la socket du serveur
    int sockAccept; //canal de la socket venant de se connecter au serveur
    vector <int> connexions; //collection des canaux connectés au serveur  
};

#endif /* INITCUBESERVEUR_H */

