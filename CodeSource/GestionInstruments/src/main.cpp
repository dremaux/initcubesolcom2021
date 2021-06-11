#include <iostream>
#include <string>
#include "gInstrument.h"

using namespace std;

int main(){
        
    mongocxx::instance instance{};
    GestionInstrument * gInstrument = new GestionInstrument();

    //cout << "Content-Type: text/html\r\n\r\n";

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