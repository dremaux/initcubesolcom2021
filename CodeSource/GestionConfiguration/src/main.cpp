#include <iostream>
#include <string>
#include "gConfiguration.h"


using namespace std;

int main(){
    
    mongocxx::instance instance{};
    GestionConfiguration * gConfiguration = new GestionConfiguration();

    cout << "Content-Type: text/html\r\n";
	cout << "Cache-Control: no-cache\r\n";

    std::string toto;
    std::getline(std::cin,toto);
    gConfiguration->stockerConfiguration(toto);

    gConfiguration->restituerDerniereConfiguration();
    gConfiguration->transmettreConfiguration();
 
    return 0;    
}

//{ "CMD": {"ID": "1","TYPE": "MEASURE","TYPEMEASURE": "TC"}}