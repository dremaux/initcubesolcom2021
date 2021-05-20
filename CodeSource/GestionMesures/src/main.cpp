#include <iostream>
#include <string>
#include "gMesures.h"

using namespace std;

int main(){
    
    mongocxx::instance instance{};
    GestionCommandes * gCommandes = new GestionCommandes();
    
    return 0;    
}
