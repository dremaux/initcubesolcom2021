#include <iostream>
#include <string>
#include "gCommandes.h"


using namespace std;

int main(){
    
    mongocxx::instance instance{};
    GestionCommandes * gCommandes = new GestionCommandes();

    //cout << "Content-Type: text/html\r\n";
	//cout << "Cache-Control: no-cache\r\n";

    //cout << "Affichage des 50 dernières commandes" << endl;
    //gCommandes->getDernieresCommandes(10); 
    //gCommandes->transmettreCommandes();
    
    //cout  << "Affichage des commandes transmises à une date et une herue précises" << endl;
    //gCommandes->rechercherCommandesParDate("2021/05/23 23:40");

    //cout  << "Affichage des commandes transmises à une date et une herue précises" << endl;
    //gCommandes->rechercherCommandesParDate("2021/05/23 23:40");
    //gCommandes->transmettreCommandes();
    
    std::string ma_trame=R"({ "CMD": {"ID": "1","TYPE": "MEASURE","TYPEMEASURE": "TC", "dateEnvoi": "0000/00/00 00:00:00"}})";
    gCommandes->stockerCommande(json::parse(ma_trame));
    
    return 0;    
}

/*
./mongod --storageEngine=mmapv1 --journal

./mongod

*/
