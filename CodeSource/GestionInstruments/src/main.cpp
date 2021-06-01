#include <iostream>
#include <string>
#include "gInstrument.h"

using namespace std;

int main(){
        
    mongocxx::instance instance{};
    GestionInstrument * gInstrument = new GestionInstrument();

    cout << "Content-Type: text/html\r\n\r\n";
	//cout << "Cache-Control: no-cache\r\n";
/*
    gInstrument->getListeInstruments();
    gInstrument->transmettreInstruments();
 */   

    std::string toto;
    cin >> toto;
    gInstrument->stockerInstrument(json::parse(toto));

    cout << "OK";
    return 0;    
}


/*
./mongod --storageEngine=mmapv1 --journal

./mongod
*/

// {"ID" : "1" , "nom" : "temperature"}
// {"ID":"1","nom":"temp erature"}

// {"identifiant": "Matrice","listeTypesMesure": [ { "code": "TC","nom": "temperature","unite": "°C","valMax": "90","valMin": "-40" },{ "code": "PIX","nom": "matrice","unite": "°C","valMax": "90","valMin": "-40" } ],"nom": "Camera_infrarouge","ref":"123BCD","role": "mesurer_une_temperature" }

// {"identifiant":"Matrice", "listeTypesMesure":[ { "code" : "TC", "nom" : "temperature", "unite" : "°C", "valMax" : "90", "valMin" : "-40" }, { "code" : "PIX", "nom" : "matrice", "unite" : "°C", "valMax" : "90", "valMin" : "-40" } ], "nom" : "Camera_infrarouge", "ref" : "123BCD", "role" : "mesurer_une_temperature" }