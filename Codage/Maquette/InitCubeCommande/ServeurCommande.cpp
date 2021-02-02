/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServeurCommande.cpp
 * Author: snir2g2
 * 
 * Created on 5 mars 2020, 13:39
 */

#include "ServeurCommande.h"

#define NB_CLIENT_MAX 1
#define PORT 9925
#define ADRESSE "127.0.0.1"

ServeurCommande::ServeurCommande() {
    ecoute.sin_port=htons(PORT);//port d'écoute.
	ecoute.sin_addr.s_addr=inet_addr(ADRESSE);
	ecoute.sin_family=AF_INET;
	canal=socket(AF_INET, SOCK_STREAM,0);//Création de la socket
	if(canal<0){
		close(canal);
		perror("Erreur de creation de la socket.");
		exit(0);
	}

	if(bind(canal,(struct sockaddr*)&ecoute, sizeof(ecoute))<0){//Attachement de la socket
		close(canal);
		perror("Erreur d'attachement de la socket.");
		exit(0);
	}
}


void ServeurCommande::attendreConnexion(){
    if(listen(canal, NB_CLIENT_MAX)<0){//Ecoute du canal de la socket
		close(canal);
		perror("Erreur d'ecoute de la socket.");
		exit(0);
	}
    cout<<"En Attente De Connexion:"<<endl;
    socklen_t taille_ecoute = sizeof(ecoute);//Taille de la socket
    sockAccept=accept(canal,(struct sockaddr*)&ecoute, &taille_ecoute);//bloque l'attente de connexion.
    cout<<"Connexion du client:\r\n"<<endl;

    if(sockAccept<0){
            close(canal);
            perror("Erreur d'acceptation de la socket.");
            exit(0);
    }
    connexions.push_back(sockAccept);

}

void ServeurCommande::recevoir(char* message, int taille) {
    // si le client est connecté
    // cout <<"En attente de commande"<<endl;
    for(int i=0; i<connexions.size(); i++)
    {
        int reception =recv(connexions[i], message,taille,0);
    }
        
}



ServeurCommande::~ServeurCommande() {
    close (canal);
}

