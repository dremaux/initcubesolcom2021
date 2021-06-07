#include <iostream>
#include <string>
#include "gInstrument.h"

using namespace std;

int main(){
        
    mongocxx::instance instance{};
    GestionInstrument * gInstrument = new GestionInstrument();

    cout << "Content-Type: text/html\r\n";
	//cout << "Cache-Control: no-cache\r\n";
/*
    std::string toto;
    std::getline(std::cin,toto);
    gInstrument->stockerInstrument(toto);
    cout << "ok" << endl;
*/
/*
    gInstrument->getListeInstruments();
    gInstrument->transmettreInstruments();
*/
    gInstrument->nettoyerInstruments();
    cout<<"ok"<<endl;

    return 0;    
}

/*
{ "_id" : ObjectId("60be11615521773ed94723f2"),
{ "nom" : "Camera infrarouge", "identifiant" : "123BCD", "ref" : "CamInfra", "adresse" : "0x69", "role" : "mesurer une temperature", "listeTypesMesure" : [ { "nom" : "temperature", "code" : "TC", "description" : "Température de l'objet mesuré", "unite" : "°C", "valMax" : "90", "valMin" : "-40" }, { "nom" : "matrice", "code" : "PIX", "description" : "Matrice d'une température de l'objet mesuré", "unite" : "°C", "valMax" : "90", "valMin" : "-40" } ] }
*/