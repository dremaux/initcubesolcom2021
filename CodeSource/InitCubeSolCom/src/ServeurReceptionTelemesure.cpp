#include "ServeurReceptionTelemesure.hpp"
#define BUF_SIZE 500

ServeurReceptionTelemesure::ServeurReceptionTelemesure(int port):Serveur(port) {

}

void ServeurReceptionTelemesure::transmettre(char* message, int taille) {
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

ServeurReceptionTelemesure::~ServeurReceptionTelemesure() {

}