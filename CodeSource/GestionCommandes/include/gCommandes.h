#include <cstdint>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace learning {
constexpr char kMongoDbUri[] = "mongodb://127.0.0.1:27017";
constexpr char kDatabaseName[] = "initcube";
constexpr char kCollectionName[] = "commande";


class GestionCommandes {
    public:

        GestionCommandes();
        ~GestionCommandes();
        
        void getDerniereCommandes(int nombreCommandes);  //affiche les Dernieres commandes
        int tDCommandes(); // transmettre les dernieres commandes
        int rechercheCommandes(int date); //trouve une trame grâce à la date
    
    private:

        GestionCommandes * gCommandes;

        int DCommandes;

        mongocxx::uri uri;
        mongocxx::client client;
        mongocxx::database db;

} ;
}