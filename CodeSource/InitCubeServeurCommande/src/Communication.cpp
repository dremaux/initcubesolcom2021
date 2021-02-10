#include "Communication.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <iostream>

Communication::Communication(string adresse,string port){
	this->adresse = adresse;
	this->port = port;
	//Si la connexion ne peut être établie avec le serveur,
 	if(this->connexion()<0)
	{
		//On lance le serveur,		
	 	this->lancerInitCubeServeur();
	 	//Et on essaie de s'y connecter     
	 	this->connexion();
	}
}

//La méthode lancerInitCubeServeur() démarre le serveur InitCibeServeur
void Communication::lancerInitCubeServeur() {
	//usleep(5000000);	
	system("../InitCubeServeur/InitCubeServeur&");
}

//La méthode connexion tente de se connecter au serveur InitCubeServeur
int Communication::connexion() {
	//Declaration des variables.
    struct addrinfo hints, * res;
    int status;


    //Definition hints.
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;//Ce champ indique la famille d'adresse désirée des adresses renvoyées
    hints.ai_socktype = SOCK_STREAM;//Ce champ indique le type préféré de socket
    hints.ai_flags = AI_PASSIVE;

    //Ici, nous pouvons mettre l'adresse et le port. InitCube écoute sur le port 9927
    status = getaddrinfo(this->adresse.c_str(), this->port.c_str(), &hints, &res);
    if(status != 0)
    {
        fprintf(stderr, "Erreur info adresse\n"); //Retour en cas d'erreur sur l'adresse ou le port.
        exit(1);
    }

    socket_id = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if(socket_id < 0)
    {
        fprintf(stderr, "Erreur création socket \n"); //Retour en cas d'erreur sur la création du socket.
        exit(2);
    }

    status = connect(socket_id, res->ai_addr, res->ai_addrlen);
    if(status < 0)
    {
        fprintf(stderr, "Erreur de connexion \n"); //Retour en cas d'un problème de connexion
        return -1;
    }
	return 0;
}

Communication::~Communication() {

}

void Communication::envoyerMessage(string m){
	for (int i=0; i<2000; i++)
         buffer[i] = 0;
	strcpy(buffer, m.c_str());
    send(socket_id, buffer, sizeof(buffer), 0);
}

int Communication::recevoirDonnees() {
    int i,retour ;
    for (i=0; i<2000; i++)
         buffer[i] = 0;
    retour = recv(socket_id, buffer,2000 , 0);
	return retour; 
//  std::cout << "data:"<<buffer<<"\r\n\r\n" << std::endl;
}

char* Communication::getBuffer() {

    return buffer;
}
