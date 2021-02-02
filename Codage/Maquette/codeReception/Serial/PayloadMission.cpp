/* Boulanger Gabrielle-Anne
 * stoque la mission d'une trame
 * ligne de compilation :
 * création de 29/04/2020
 */
#include "PayloadMission.h"
#include "TypeMesure.h"
#include <iostream>

using namespace std;

PayloadMission::PayloadMission(char* PayloadBrut){
	cout<<" \n Création de l'objet Payload Mission appartir du pointeur PayloadBrut"<<endl; // type = 1
}
PayloadMission::~PayloadMission(){
	cout<<" \n Destruction de l'objet Payload Mission"<<endl;
}
