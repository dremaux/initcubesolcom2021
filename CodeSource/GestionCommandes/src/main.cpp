#include <iostream>
#include <string>
#include "gCommandes.h"

using namespace std;

int main(){
    
    //création de l'instance de Mongocxx qui doit être unique pour chaque programme
    mongocxx::instance instance{};

    GestionCommandes * gCommandes = new GestionCommandes();

    //Récupération et transmission de toutes les dernières commandes
    cout << "nombre de commandes reçues : " << gCommandes->getDernieresCommandes() << endl;
    gCommandes->transmettreCommandes();

    //Récupération et transmission des 5 dernières commandes
    cout << "nombre de commandes reçues : " << gCommandes->getDernieresCommandes(5) << endl;
    gCommandes->transmettreCommandes();

    //Recherche par date
    cout << "Recherche par la date :" << endl;
    gCommandes->rechercherCommandesParDate("2021-05-14");
    gCommandes->transmettreCommandes();

    return 0;    
}