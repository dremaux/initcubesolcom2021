///Inclusions 
#include <iostream>
#include "Serial.h"

using namespace std;
///Début du code principal
int main()
{
	///initialisation des variables
	int a =1; //permet un boucle 'infinie'
	string message;	//creer la variable pour le message
	Serial maLiaisonSerie("/dev/ttyUSB0", 9600); //reçois un message avec un débit de 9600 sur le port ttyUSB0
	while (a==1) ///boucle infinie
	{
		message = maLiaisonSerie.readLine(); //stocke les informations recues dans message
		cout << "Message reçu : "<< message <<endl; //affiche les informations reçues
		
		/*Décortication de la trame*/
		
		char mess[message.size()+1]; //création d'un tableau de carractère pour stocker la reception
		strcpy(mess, message.c_str()); //Copie le string recue pour le placer dans la nouvelle chaîne de carractère
		
		
		/*
		/*Création tableau pour décortication/
		char id[2]; 
		char nbOctetTrame[1];
		char checksum[2];
		/*Décortication/
		for (int i=0 ; i<=1; i++){ ///ID
			id[i] = mess[i];
		}
		nbOctetTrame[0]=mess[2]; ///NB d'octet dans la trame
		for (int i=1; i<=0; i --){ ///checksum
			checksum[i];
		}

		/*Affichage des données séparés/
		cout<<"id :" << id << endl;
		cout<<"nombre d'octet :" << nbOctetTrame <<endl;
		*/
	
	
	}
}
