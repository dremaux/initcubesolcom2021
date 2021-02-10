/* Boulanger Gabrielle-Anne
 * classe qui ....
 * ligne de compilation :
 * fait le 29/04/2020
 */
#include "Payload.h"
#include "Trame.cpp"
#include <iostream>

using namespace std;

Payload::Payload(char* _payloadBrut){ //modification de cette classe pour quel que chose de cohérent? (lopes)
	//Ici, il faut ajouter l'initialisation de l'attribut payloadBrut avec le paramètre.
	int tailleTabDonnees = strlen(_payloadBrut);
	for (int i=0; i<tailleTabDonnees ; i++){
		payloadBrut[i]= _payloadBrut[i];
	}
	cout<<" \n Création de l'objet Payload apparttir du pointeur PayloadBrut"<<endl;
	cout<<" payloadBrut = " << payloadBrut << endl; 
}
Payload::~Payload(){
	cout<<" \n Destruction de l'objet Payload"<<endl;
}
void Payload::extraireInformations(){
	cout <<" \n Extraction des informations de la Trame"<<endl;
}
