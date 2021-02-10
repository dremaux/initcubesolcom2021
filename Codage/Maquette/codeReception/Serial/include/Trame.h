/* BOULANGER GABRIELLE-ANNE
 * Trame.h
 * ligne de compilation :
 * fait le 29/04/2020
 */
 
#ifndef TRAME_H
#define TRAME_H

//#define TAILLE_MAX 104
#include "Payload.h"
#include "TypeTrame.h"

class Trame {
	public :
		Trame(char* trameBrute);
		~Trame();
		void decortiquer(); 			//initialisation de la fonction de décortiquation de trame
		void decortiquerPayload(); 		//initialisation d'une fonction poour décortiquer le payload
		
		//Quelle est le rôle de cette méthode?
		//Il faut la renommer en identifierTypeTrame()
		//Doit-elle retourner uen valeur ou directement modifier l'attribut typeTrame?
		//int idTypeTrame();
		//dans Trame.cpp, la méthode ne retourne rien donc on choisit cette optiono
		void idTypeTrame();
	private :
		char* trameBrute; 				//initialisation d'un tableau contenant la trame reçue
		char id [2];					//initialisation de la varriable contenant l'id transmis par la trame
		int nbreOctets;					//initialisation de la varriable contenant le nombre d'octet dans la trame
		char checksum;					//initialisation de la varriable contenant le checksum
		TypeTrame typeTrame;			//initialisation de la varriable stoquant le type de trame reçue
		bool verrifierChecksum();		//initialisation d'une fonction verrifiant la validité d'une trame
		Payload *payload;				//initialisation d'un objet probenant d'une classe abstraite
};

#endif /* TRAME_H */
