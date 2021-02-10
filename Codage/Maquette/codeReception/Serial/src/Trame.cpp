/* BOULANGER GABRIELLE-ANNE
 * Trame.cpp
 * ligne de compilation :
 * fait le 29/04/2020
 */

#include "Trame.h"
//#include "TypeTrame.h"
#include <iostream>
#include <string.h>


//#define	TAILLE_MAX		104	//déjà défini dans le .h
#define DEBUT	3

using namespace std;

Trame::Trame(char* trameBrute){
	cout<<" \n Création de l'objet trame"<<endl;
	
	//*****************************************************************************************
	//* Partie importante :
	//* Initialisation de l'attribut trameBrute (attribut => this->) avec le paramètre passé entre les parenthèses
	//*****************************************************************************************
	this->trameBrute = trameBrute;
	
	this->nbreOctets = (int)trameBrute[2]; 									/// NB d'octet dans la trame
	cout<<"\n nb octets trame : "<< nbreOctets <<endl;
	
	//int f=0;
	//for (int i=0 ; i<=1; i++){ 											/// ID
	//	id[i] = trameBrute[i];
	//}
}

Trame::~Trame(){
	cout<<" \n Destruction de l'objet trame"<<endl;
}

void Trame::decortiquer(){
	int f=0;
	int g=3;
	cout <<" \n Decortication de la Trame"<<endl;
	for (int i=0 ; i<2; i++){ 											/// ID
		id[i] = trameBrute[i];
	}
	this->nbreOctets = (int)trameBrute[2]; 									/// NB d'octet dans la trame
	cout<<"\n nb octets trame : "<< nbreOctets <<endl;
	
	//***************************************
	//Utilisation ou calcul du checksum à reprendre. Je n'ai pas compris
	//**************************************
	//for (int i=1; i<=0; i --){ 											///checksum
	//	checksum2[i];
	//}
	//************************************
	
	//Code à revoir :
	//************************************
	//int taille=0;
	//this->IdTypeTrame(DEBUT; Taille);
	//***********************************
																		/// Données 
	int caseDebutDonnees = g+f;
	int tailleTabDonnees = strlen(trameBrute)-caseDebutDonnees-2;
	char donnees[tailleTabDonnees];
	cout<< "les Données brut "<< endl;
	cout <<"taille des données calculées : "<<tailleTabDonnees<<" Octets"<<endl;
	for (int h=0; h < tailleTabDonnees; h++){
		int pointeur = h+caseDebutDonnees ;
		donnees[h] = trameBrute[pointeur];
		//Pourrait se faire en une ligne :
		//donnees[h] = trameBrute[caseDEbutDonnes+h];
 	}
	cout <<"Les données récupérées sont les suivantes : \n"<<donnees<<endl;
	
}


void Trame::decortiquerPayload(){
	cout<<" \n Decortication du payload"<<endl;
	
}


bool Trame::verrifierChecksum(){
	cout<<"\n Verrification du checksum"<<endl;
	//Attention, la suite est à revoir, elle est différente de votre Confinement.cpp
	for (int i=1; i<=0; i --){ 											///checksum
		//Que fait-on avec cette case de tableau?
		//checksum2[i];
	}
	//ces variables n'ont pas été déclarées
	//checksums=checksum2[0]^checksum2[1];
	//cout << checksums <<endl ;
	char checksumx = trameBrute[0];									 		/// verrification de validité trame
	for (int i=1;i<strlen(trameBrute);i++)
	{
		checksumx^=trameBrute[i];
	}
	//Ici il faudrait comparer checksumx avec l'attribut checksum 
	//et non pas avec une variable checksums qui n'a pas été déclarée.
	//if (checksums == checksumx){
	if (this->checksum == checksumx) {
		//Attention pour que le test fonctioonne, il faut au préalable
		//avoir intialisé l'attribut checksum. Pour cela il faudrait créer
		//une méthode privée extraireChecksum() qui trouve le checksum
		//dans la trame puis qui le stocke dans checksum

		//penser au retour(return quoi?)
		cout << "trame valide" << endl;
	}
	else{
		//return quoi?
		cout <<"trame non valide"<<endl;
	}
	
}

//Renommer la méthode en identifierTypeTrame() et elle doit être privée
void Trame::idTypeTrame(){
	//-> Identification de type de trame 
	//la 1er indication pour la commande se situe à la 3e case // 9 possibilités de commande
	
	//Attention, ici, g n'existe pas!
	//on le crée et on l'initialise
	TypeTrame type;
	int f=0;
	int g=3;
	if (trameBrute[g]=='D' && trameBrute[g+1]=='E'){							//si les 2 1er lettres sont DE
		type = DEPLOY;f=6;														///DEPLOY   6 //4
	}
	if (trameBrute[g]=='D' && trameBrute[g+1]=='A'){							//si les 2 1er lettres sont DA
		type = DATE; f=4;														///DATE     4 //9
	}
		
	if (trameBrute[g]=='E'){													//si la 1er lettre est E
		type = EMPTY; f=5; 														///EMPTY    5 //6
	}
	if (trameBrute[g]=='M' && trameBrute[g]=='I'){	 							//si les 2 1er lettres sont MI
		type = MISSION; f=7;													///MISSION  7 //1
	}
	if (trameBrute[g]=='M' && trameBrute[g+1]=='E' && trameBrute[g+2]=='E'){ 	//si les 3 1er lettres sont MEE 
		type = MEETING; f=7; 													///MEETING  7 //8
	}
	if (trameBrute[g]=='M' && trameBrute[g+1]=='E' && trameBrute[g+2]=='A'){	//si les 3 1er lettres sont MEA
		type = MEASURE; f=7; 													///MEASURE  7 //2
	}
		
	if (trameBrute[g]=='S' && trameBrute[g+1]=='A'){							// si les 2 1er lettres sont SA
		type = SAVE ; f=4;                              	                   ///SAVE     4 //7
	}
	if (trameBrute[g]=='S' && trameBrute[g+1]=='U'){        	           		// si les 2 1er lettres sont SU	
		type = SURVUVAL ; f=8; 													///SURVIVAL 8 //5
	}
	if (trameBrute[g]=='S' && trameBrute[g+1]=='T' ){							// si les 2 1er lettres sont ST
		type = STATUS ; f=6; 													///STATUS   6 //3
	}
	char CMD[f];
	if(f==0) {																	//Si rien ne correspond 
		type = ERROR;															/// ERROR     //10
		cout <<"ERREUR :: trame de commmande introuvable \n"<<endl;
	}
	this->typeTrame = type;
}
