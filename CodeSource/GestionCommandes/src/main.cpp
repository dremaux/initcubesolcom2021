#include <iostream>
#include <string>
#include "gCommandes.h"

using namespace std;

int main(){
    
    mongocxx::instance instance{};
    GestionCommandes * gCommandes = new GestionCommandes();

    cout << "Content-Type: text/html\r\n";
	cout << "Cache-Control: no-cache\r\n";

    cout << "trame enregistrer, et ajout de la date : ";
    std::string ma_trame=R"({ "CMD": {"ID": "1","TYPE": "MEASURE","TYPEMEASURE": "TC", "dateEnvoi": "0000/00/00 00:00:00"}})";
    gCommandes->stockerCommande(json::parse(ma_trame));

    cout << "Affichage des 5 dernieres commandes" << endl;
    gCommandes->getDernieresCommandes(5); 
    gCommandes->transmettreCommandes();
    
    cout  << "Affichage des commandes transmises à une date et une herue précises" << endl;
    gCommandes->rechercherCommandesParDate("2021/06/03 12:40");
 
    return 0;    
}