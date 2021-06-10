/// Les inclusions
#include "Serial.h"

#ifndef COMINITCUBE_H
#define COMINITCUBE_H

using namespace std;

class ComInitCube
{
    private:

    /**
     * /// AttendreAck() va nous permettre de vérifier si le cube nous renvoie un ACK ou un NACK. 
     */
    string attendreAck();

    Serial* maLiaisonSerie;
	
    mutex* mtx;
    
    /**
     * /// VerifierChecksum() va comparer le checksum recu et le checksum que l'on a calculé grâce à calculerChecksum().
     * 
     * Paramètre "trame": 
     * Paramètre "taille": 
     */
    bool verifierChecksum(unsigned char* trame, int taille);
    
    /**
     * /// CalculerChecksum() calcule le checksum pour ensuite le vérifier avec verifierChecksum().
     * 
     * Paramètre "trame": 
     * Paramètre "PF": 
     * Paramètre "pf": 
     * Paramètre "taille": 
     */
    void calculerChecksum( unsigned char* trame, unsigned char & PF, unsigned char & pf, int taille);


    public:

    /**
     * /// Constructeur principal.
     * 
     * Paramètre "port": Indique quel est le port que nous allons utiliser ("ttyAMA0" ou "ttyS0")
     * Paramètre "baud_rate": Indique quelle va être la vitesse de transmission (Le protocole ZigBee ne fonctionne qu'en 9600) 
     */
    ComInitCube(std::string port, unsigned int baud_rate);

    /**
     * /// TransmettreTrame() nous permet d'envoyer une trame par le port série.
     * 
     * Paramètre "s": Tableau dans lequel nous stockons la trame pour qu'elle reste intacte.
     */
    void transmettreTrame(unsigned char* s);

    /**
     * /// LireTrame() nous permet de lire une trame recue par le port série ainsi que de vérifier si le checksum de la trame recue est correcte.
     * 
     * Paramètre "trame": Le tableau dans lequel nous allons stocker la trame recue intacte.
     * Paramètre "taille": On s'en sert pour indique combien de case/caractères composent le tableau.
     */
    bool lireTrame(unsigned char* trame, int taille);

};

#endif
