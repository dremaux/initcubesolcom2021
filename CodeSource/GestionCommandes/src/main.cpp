#include <iostream>
#include <string>
#include "gCommandes.h"

using json=nlohmann::json;
using namespace std;

int main(){
    
    mongocxx::instance instance{};
    GestionCommandes * gCommandes = new GestionCommandes();
    cout << "Affichage des 50 dernières commandes" << endl;
    cout << "nombre de commandes reçus :" << gCommandes->getDernieresCommandes(50) << endl;
    gCommandes->transmettreCommandes();

    
    cout  << "Affichage des commandes transmises à une date et une herue précises" << endl;
    gCommandes->rechercherCommandesParDate("2021/05/23 23:40");
    //gCommandes->transmettreCommandes();

    json ma_trame=R"({ "CMD": {"ID": "1","TYPE": "MEASURE","TYPEMEASURE": "TC"}})"_json;
    gCommandes->stockerCommande(ma_trame);
    
    return 0;    
}

/*
./mongod --storageEngine=mmapv1 --journal

./mongod
*/