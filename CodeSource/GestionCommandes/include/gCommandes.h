#pragma once

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

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

using namespace std;

class GestionCommandes {
    public:

        GestionCommandes();
        ~GestionCommandes();
        
        int getDCommandes(int nombreCommandes);  //affiche les Dernieres commandes
        int tDCommandes(); // transmettre les dernieres commandes
        int rechercheCommandes(int date); //trouve une trame grâce à la date
    
    private:

        GestionCommandes * gCommandes;

        int getDCommandes;

        mongocxx::instance instance{};
        mongocxx::client client{mongocxx::uri{}};

        mongocxx::database db = client["initcube"];
        mongocxx::collection coll = db["commande"];

}