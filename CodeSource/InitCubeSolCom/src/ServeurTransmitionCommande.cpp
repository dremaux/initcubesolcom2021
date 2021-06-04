#include "ServeurTransmitionCommande.hpp"

ServeurTransmitionCommande::ServeurTransmitionCommande(int port): Serveur(port) {
    mtx = new mutex();
}

ServeurTransmitionCommande::~ServeurTransmitionCommande() {
    delete mtx;
}

/*
n = position du canal d'écoute dans la colection 
*/
int ServeurTransmitionCommande::attendreCommande(int n){
    int i,retour = 0;
    char buffer[TAILLEBUFFER];
    
    for (i=0; i<TAILLEBUFFER; i++){
        buffer[i] = 0;
    }
    retour = recv(connexionsM[n], buffer,TAILLEBUFFER , 0);
    
    
    if(retour==0){
        perror("Client partie");
        
        connexionsM.erase(n);
        cout << "Nombre de clients connectés : " << connexionsM.size() << endl;
        cout << "En Attente De Connexion:"<<endl;
        return(-1);
    
    }
    else{
        mtx->lock();
        recu.push(buffer);
        mtx->unlock();
        send(connexionsM[n],"ACK",3,0);
        cout<<buffer;
    }
    return(1);
}

void ServeurTransmitionCommande::effacerPremierRecu(){
    recu.pop();
}

queue <string> ServeurTransmitionCommande::getRecu(){
    return recu;
}

mutex* ServeurTransmitionCommande::getMutex(){
    return mtx;
}