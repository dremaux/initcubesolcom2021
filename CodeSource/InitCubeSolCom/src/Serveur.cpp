#include "Serveur.hpp"

#define NB_CLIENT_MAX 50
#define ADRESSE "127.0.0.1"

Serveur::Serveur(int port) {
    iterateur = 0;
    ecoute.sin_port=htons(port);//port d'écoute.
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

//retourne la position de la socket dans la map et retourne -1 si erreur
int Serveur::attendreConnexion(){
    if(listen(canal, NB_CLIENT_MAX)<0){//Ecoute du canal de la socket
		close(canal);
		perror("Erreur d'ecoute de la socket.");
		return -1;
	}
   	cout << "En Attente De Connexion:"<<endl;
    socklen_t taille_ecoute = sizeof(ecoute);//Taille de la socket
    sockAccept=accept(canal,(struct sockaddr*)&ecoute, &taille_ecoute);//bloque l'attente de connexion.
    if(connexionsM.size()< NB_CLIENT_MAX){
        cout << "Connexion d'un nouveau client."<<endl;
    	if(sockAccept<0){
            close(canal);
            perror("Erreur d'acceptation de la socket.");
            return -1;
        }
	    //Ajout de la socket à la liste des clients
        iterateur++;
        connexionsM[iterateur] = sockAccept;
        connexionsV.push_back(sockAccept);
	    cout << "Nombre de clients connectés : " << connexionsV.size() << endl;
        return iterateur;
    }
    else{
        close(sockAccept);
        cout<<"Trop de client connectés"<<endl;
        return -1;
    }
}

Serveur::~Serveur() {

}