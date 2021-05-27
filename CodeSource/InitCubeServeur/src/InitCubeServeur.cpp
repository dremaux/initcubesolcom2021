#include "InitCubeServeur.h"


#define NB_CLIENT_MAX 20
#define ADRESSE "127.0.0.1"
#define BUF_SIZE 500


using json = nlohmann::json;

using namespace std;

/*
port = num port du serveur
 */
InitCubeServeur::InitCubeServeur(int port){
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
//retourne la position de la socket dans la map
int InitCubeServeur::attendreConnexion(){
    
    if(listen(canal, NB_CLIENT_MAX)<0){//Ecoute du canal de la socket
		close(canal);
		perror("Erreur d'ecoute de la socket.");
		return -1;
	}
   	cout << "En Attente De Connexion:"<<endl;
    socklen_t taille_ecoute = sizeof(ecoute);//Taille de la socket
    sockAccept=accept(canal,(struct sockaddr*)&ecoute, &taille_ecoute);//bloque l'attente de connexion.
    if(connexions.size()< NB_CLIENT_MAX){
        cout << "Connexion d'un nouveau client."<<endl;
    	if(sockAccept<0){
            close(canal);
            perror("Erreur d'acceptation de la socket.");
            return -1;
        }
	    //Ajout de la socket à la liste des clients
        iterateur++;
        connexions[iterateur] = sockAccept;
        connexionsV.push_back(sockAccept);
	    cout << "Nombre de clients connectés : " << connexions.size() << endl;
        return iterateur;
    }
    else{
        close(sockAccept);
        cout<<"Trop de client connectés"<<endl;
        return -1;
    }
}

/*
n = position du canal d'écoute dans la colection 
*/
int InitCubeServeur::attendreCommande(int n){
    int i,retour = 0;
    char buffer[TAILLEBUFFER];
    
    for (i=0; i<TAILLEBUFFER; i++){
        buffer[i] = 0;
    }
    retour = recv(connexions[n], buffer,TAILLEBUFFER , 0);
    
    
    if(retour==0){
        perror("Client partie");
        
        connexions.erase(n);
        cout << "Nombre de clients connectés : " << connexions.size() << endl;
        cout << "En Attente De Connexion:"<<endl;
        return(-1);
    
    }
    else{
        mtx->lock();
        reçu.push_back(buffer);
        mtx->unlock();
        send(connexions[n],"ACK",3,0);
        cout<<buffer;
    }
    return(1);
}

void InitCubeServeur::effacerPremierRecu(){
    reçu.erase(reçu.begin());
}

void InitCubeServeur::afficherCommande(string buff){
    cout << buff << endl;
}

void InitCubeServeur::transmettre(char* message, int taille) {
    char buf[BUF_SIZE];
	for(int i=0; i<connexionsV.size(); i++) {
        int envoyer = send(connexionsV[i], message,taille,0);
        int reception = recv(connexionsV[i],buf,BUF_SIZE,MSG_DONTWAIT);
		//Si un client se déconnecte, on le supprime de la liste        
		if(reception==0) {
        	close(connexionsV[i]);
			connexionsV.erase(connexionsV.begin()+i);
			cout << "Déconnexion d'un client" << endl;
			cout << "nombre de clients restants : " << connexionsV.size() << endl;
            i--;
        }
    }
}

InitCubeServeur::~InitCubeServeur() {
    close(canal);
}