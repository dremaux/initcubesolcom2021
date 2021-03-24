/* Boulanger Gabrielle-Anne
 * classe qui ....
 * ligne de compilation :
 * création de 29/04/2020
 */

#include "PayloadMesure.h"
//#include "TypeMesure.h"
#include <iostream>

using namespace std;

PayloadMesure::PayloadMesure(char* _payloadBrut ):Payload(_payloadBrut){ //ajout du constructeur de Payload pour quel que chose de cohérent? (lopes)
	//doit initialiser l'attribut payloadBrut type = 2 ;
	cout<<" \n Création de l'objet Payload Mesure "<<endl;
}

 void PayloadMesure::extraireInformations() {
	//extraction des infos
	cout<<" \n Extraction des infos "<<endl;

}

PayloadMesure::~PayloadMesure(){
	cout<<" \n Destruction de l'objet Payload Mesure "<<endl;
}
