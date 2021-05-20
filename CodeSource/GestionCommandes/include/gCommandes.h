#include <cstdint>
#include <string.h>
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

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;

using namespace bsoncxx;
using namespace std;




class GestionCommandes {
    public:

        GestionCommandes();
        ~GestionCommandes();
        
        //récupère les <nombre> dernières commandes, toutes les commandes si le nombre n'est pas spécifié (=0 par défaut <=> pas de limite)
        //les commandes sont stockées dans l'attribut dernieresCommandes
        int getDernieresCommandes(int nombre=0);  

        //transmet les dernières commandes récupérées avec getDernieresCommandes()
        int transmettreCommandes();

        //trouve une trame grâce à la date
        int rechercherCommandesParDate(std::string date); 
    
    private:

        mongocxx::client client{mongocxx::client{mongocxx::uri{}}};
        mongocxx::database db;
        mongocxx::collection coll;
        
        vector<std::string> commandes;
};