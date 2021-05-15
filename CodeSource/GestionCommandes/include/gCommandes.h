#include <cstdint>
#include <string>
#include <iostream>
#include <vector>

#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>

using namespace std;




class GestionCommandes {
    public:

        GestionCommandes();
        ~GestionCommandes();
        
        int getDerniereCommandes();  //affiche les Dernieres commandes
        int tDCommandes(); // transmettre les dernieres commandes
        int rechercheCommandes(); //trouve une trame grâce à la date
    
    private:

        GestionCommandes * gCommandes;

        int DerniereCommandes;

        mongocxx::uri uri;
        mongocxx::client client;
        mongocxx::database db;
        mongocxx::collections coll;
        


};