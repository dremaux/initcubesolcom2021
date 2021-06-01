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

#include "json.hpp"

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;

using json=nlohmann::json;
using namespace bsoncxx;
using namespace std;
using json=nlohmann::json;



class GestionCommandes {
    public:

        GestionCommandes();
        ~GestionCommandes();
        
<<<<<<< HEAD
=======

>>>>>>> 88320fe8d01c7a511f8bf4313f0555ea21f13dcf
        int getDernieresCommandes(int nombre=0);  
        int transmettreCommandes();
        int rechercherCommandesParDate(std::string date); 
	    int stockerCommande(json commande);
    
    private:

        mongocxx::client client{mongocxx::client{mongocxx::uri{}}};
        mongocxx::database db;
        mongocxx::collection coll;
        
        vector<std::string> commandes;
};