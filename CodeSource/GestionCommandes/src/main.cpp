#include <iostream>
#include <string>
#include "gCommandes.h"


using namespace std;

int main(){
    
    mongocxx::instance instance{};
    GestionCommandes * gCommandes = new GestionCommandes();
    cout << "Affichage des 50 dernières commandes" << endl;
    cout << "nombre de commandes reçus :" << gCommandes->getDernieresCommandes(50) << endl;
    gCommandes->transmettreCommandes();

<<<<<<< HEAD
    cout << "Content-Type: text/html\r\n";
	cout << "Cache-Control: no-cache\r\n";

    //cout << "Affichage des 50 dernières commandes" << endl;
    gCommandes->getDernieresCommandes(10); 
    gCommandes->transmettreCommandes();

    
    //cout  << "Affichage des commandes transmises à une date et une herue précises" << endl;
    //gCommandes->rechercherCommandesParDate("2021/05/23 23:40");
=======
    
    cout  << "Affichage des commandes transmises à une date et une herue précises" << endl;
    gCommandes->rechercherCommandesParDate("2021/05/23 23:40");
>>>>>>> 88320fe8d01c7a511f8bf4313f0555ea21f13dcf
    //gCommandes->transmettreCommandes();

    json ma_trame=R"({ "CMD": {"ID": "1","TYPE": "MEASURE","TYPEMEASURE": "TC"}})"_json;
    gCommandes->stockerCommande(ma_trame);
    
    return 0;    
}

/*
./mongod --storageEngine=mmapv1 --journal

./mongod
<<<<<<< HEAD
*/
=======
*/
>>>>>>> 88320fe8d01c7a511f8bf4313f0555ea21f13dcf
