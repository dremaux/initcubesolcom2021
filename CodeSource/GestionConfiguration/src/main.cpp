#include <iostream>
#include <string>
#include "gConfiguration.h"


using namespace std;

int main(){
    
    mongocxx::instance instance{};
    GestionConfiguration * gConfiguration = new GestionConfiguration();

    cout << "Content-Type: text/html\r\n\r\n";
	
/*
    std::string toto; 
    std::getline(std::cin,toto);
    gConfiguration->stockerConfiguration(toto);
    cout << "OK" << endl; 
*/

/*
    gConfiguration->restituerDerniereConfiguration();
    gConfiguration->transmettreConfiguration();
*/
    return 0;    
}