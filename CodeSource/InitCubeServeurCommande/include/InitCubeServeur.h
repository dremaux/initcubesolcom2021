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
#define TAILLEBUFFER 2000

#include "Lib.h"
#include <thread>

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
    int attendreCommande(int fd);
    void afficherCommande(string buff);
    void nouvelleConnexion();
    thread member1Thread();

  private:
    
    struct sockaddr_in ecoute;  //Structure de la socket
    int canal;  //canal de la socket du serveur
    int sockAccept; //canal de la socket venant de se connecter au serveur
    vector <int> connexions; //collection des canaux connectés au serveur 
    vector <string> reçu; //collection de commande reçu
    
};

#endif /* INITCUBESERVEUR_H */

