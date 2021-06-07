#include <iostream>
#include <string>
#include "gInstrument.h"

using namespace std;

int main(){
        
    mongocxx::instance instance{};
    GestionInstrument * gInstrument = new GestionInstrument();

    cout << "Content-Type: text/html\r\n";
	cout << "Cache-Control: no-cache\r\n";

    std::string toto;
    std::getline(std::cin,toto);
    gInstrument->stockerInstrument(toto);
    cout << "ok" << endl;
/*
    gInstrument->getListeInstruments();
    gInstrument->transmettreInstruments();
*/
    return 0;    
}

// {"ID" : "1" , "nom" : "tempe rature"}
// {"ID":"1","nom":"temper\u0020ature"}
