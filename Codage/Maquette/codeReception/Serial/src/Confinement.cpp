/* ligne de compilation : g++ Confinement.cpp -o testConfinement -lboost_system -lpthread
 * Boulanger Gabrielle-Anne 
 * code principal
 * fait en Mars-Avril 2020
 */
/// Inclusions 
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//#include <boost/asio.hpp>

using namespace std;
/// Début du code principal
int main()
{
	/* Création de trame */ 											//Commenge
	
	//Déclaration et inititialisation de la trame	
	char trame[100]={'\0'};												///Très important pour marquer la fin de la chaine de caractères
	///Construction de la trame
	///identifiant	
	trame [0]='~';
	trame [1]='1';
	///taille provisoire de la trame
	trame[2]=strlen(trame);
	///ajout du type de trame
    strcat(trame,"STATUS");
	///nombre de paquets
	trame[strlen(trame)]=1;
	///numéro du paquet
	trame[strlen(trame)]=1;
	///données utiles
	strcat(trame,"-BORD-SMo1570-S%25-RMo1249-R%35-DT2020/03/28 12:19:25 -T25.9 ");
	///maintenant que la trame est complète (hors checksum)
	///on met à jour la taille de la trame dans la troisième case (=  case 2)
	trame[2]=strlen(trame);
	///calcul du checksum (OU exclusif entre chaque octet de la trame)
	char checksum = trame[0];
	for (int i=1;i<strlen(trame);i++)
	{
		checksum^=trame[i];
	}
	///ajout du checksum à la fin de la trame
	trame[strlen(trame)]=checksum;

	///affichage de la trame et de sa taille
	cout << "Trame : " << trame << endl;	
	cout << "Taille de la trame checksum compris : "<<strlen(trame)<<endl;
	cout << "Extraction du checksum : "<< trame[trame[2]]<< endl;
	///initialisation des variables
																		//// Gabrielle
	cout <<endl;
	cout <<endl;
	cout <<"Décortication de la Trame \n" << endl ;
	/* Décortication de la trame */
	//char mess[]; // création d'un tableau de carractère pour stoquer la reception

	/* Création tableau pour décortication */
	char id[2]; 
	char checksum2[2];
	char status[6];
	char checksums;
	/* Décortication */
	for (int i=0 ; i<=1; i++){ 											/// ID
		id[i] = trame[i];
	}
	int nbOctetTrame = (int)trame[2]; 									/// NB d'octet dans la trame
	cout<<"\n nb octets trame : "<< nbOctetTrame <<endl;
	cout<< endl << "checksum" << endl;
	for (int i=1; i<=0; i --){ 											///checksum
		checksum2[i];
	}
	checksums=checksum2[0]^checksum2[1];
	cout << checksums <<endl ;
	char checksumx = trame[0];									 		/// verrification de validité trame
	for (int i=1;i<strlen(trame);i++)
	{
		checksumx^=trame[i];
	}
	if (checksums == checksumx){
		cout << "trame valide" << endl;
	}
	else{cout <<"non"<<endl;}
	
																		///CMD
		int f=0;
		int g=3;	// la 1er indication pour la commande se situe à la 3e case // 9 possibilités de commandes
		cout <<"Ici nous reçevons la trame suivante \n"<< trame[g]<<endl;
		if (trame[g]=='D' && trame[g+1]=='E'){							//si les 2 1er lettres sont DE
			cout<<"Trame de deploiement \n"<<endl; f=6;}				///DEPLOY   6
		if (trame[g]=='D' && trame[g+1]=='A'){							//si les 2 1er lettres sont DA
			cout<<"Trame de date \n"<<endl; f=4;}						///DATE     4
			
		if (trame[g]=='E'){												//si la 1er lettre est E
			cout<<"Trame de empty \n"<<endl; f=5;}						///EMPTY    5
			
			
		if (trame[g]=='M' && trame[g]=='I'){ 							//si les 2 1er lettres sont MI
			cout<<"Trame de mission \n"<<endl; f=7;  }					///MISSION  7
		if (trame[g]=='M' && trame[g+1]=='E' && trame[g+2]=='E'){ 		//si les 3 1er lettres sont MEE 
			cout<<"Trame de meeting \n"<<endl; f=7;}					///MEETING  7
		if (trame[g]=='M' && trame[g+1]=='E' && trame[g+2]=='A'){		//si les 3 1er lettres sont MEA
			cout<<"Trame de meeting \n"<<endl; f=7;}					///MEASURE  7
			
		if (trame[g]=='S' && trame[g+1]=='A'){							// si les 2 1er lettres sont SA
			cout<<"Trame de sauvegarde \n"<<endl; f=4;}					///SAVE     4
		if (trame[g]=='S' && trame[g+1]=='U'){	                   		// si les 2 1er lettres sont SU
			cout<<"Trame de SURVIVAL \n"<<endl; f=8;}					///SURVIVAL 8
		if (trame[g]=='S' && trame[g+1]=='T' ){							// si les 2 1er lettres sont ST
			cout<<"Trame de status \n"<<endl; f=6;}						///STATUS   6
		char CMD[f];
		if(f==0) { 
			cout <<"ERREUR :: trame de commmande introuvable \n"<<endl; 
		}

		/// Données 
		int caseDebutDonnees = g+f;
		int tailleTabDonnees = strlen(trame)-caseDebutDonnees-2;
		char Donnees[tailleTabDonnees];
		cout<< "les Données brut "<< endl;
		cout <<"taille des données calculées : "<<tailleTabDonnees<<" Octets"<<endl;
		for (int h=0; h < tailleTabDonnees; h++){
			int pointeur = h+caseDebutDonnees ;
			Donnees[h] = trame[pointeur];
		}
		cout <<"Les données récupérées sont les suivantes : \n"<<Donnees<<endl;
		
// si c'est une trame de status alors ...
// si c'est une trame de mission alors ...

		/* Affichage des données séparés*/

		int intId[2];													///Test 2 de conversion de l'id en int ; résultats plus complets
		intId[0]=(int)id[0];											//Conversion du tableau char de l'id en tableau int 
		intId[1]= (int) id[1];
		cout<<endl;
		cout <<" Id : " << id[0]<<id[1]<< endl ;
		cout<<endl;
		/*int inbOctetTrame = (int)nbOctetTrame[0]; 						/// Conversion de char en int 
		cout<<"\n nombre d'octet :" << inbOctetTrame <<endl;*/
	
}
