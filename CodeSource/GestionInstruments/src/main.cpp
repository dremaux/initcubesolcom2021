#include <iostream>
#include <string>
#include "gInstrument.h"

using namespace std;

int main(){
        
    mongocxx::instance instance{};
    GestionInstrument * gInstrument = new GestionInstrument();

    cout << "Content-Type: text/html\r\n\r\n";
	cout << "Cache-Control: no-cache\r\n";

/*
    gInstrument->getListeInstruments();
    gInstrument->transmettreInstruments();
*/    
    std::string toto;
    std::getline(std::cin,toto);
    //cout << toto << endl;

    gInstrument->stockerInstrument(toto);

    return 0;    
}
// {"ID" : "1" , "nom" : "tempe rature"}
// {"ID":"1","nom":"temper\u0020ature"}
