#include <iostream>
#include <string>
#include "gCommandes.h"

using namespace std;

int main(){
    
    mongocxx::instance instance{};
    GestionCommandes * gCommandes = new GestionCommandes();

    //cout << "nombre de commandes reçus :" << gCommandes->getDernieresCommandes(3) << endl;
    //gCommandes->transmettreCommandes();

    //gCommandes->rechercheCommandesParDate("2021/05/19");
    //gCommandes->transmettreCommandes();

    //json ma_trame=R"({ "CMD": {"ID": "1","TYPE": "MEASURE","TYPEMEASURE": "TC"}})"_json;
    //gCommandes->stockerCommande(ma_trame);
    
    return 0;    
}

/*
mongod --dbpath /data/db --repair

sudo mongod --storageEngine=mmapv1
*/