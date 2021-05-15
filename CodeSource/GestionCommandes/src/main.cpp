#include <iostream>
#include "gCommandes.h"

using namespace std;

int main(){

    GestionCommandes * gCommandes = new GestionCommandes();

    gCommandes->getDerniereCommandes();

    return 0;    
}