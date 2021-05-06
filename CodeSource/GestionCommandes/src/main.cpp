#include <iostream>
#include "gCommandes.h"

using namespace std;

int main(int argc, char** argv){

    GestionCommandes * GCommandes = new GestionCommandes();

    GCommandes->getDerniereCommandes(int nombreCommandes);

    return 0;    
}