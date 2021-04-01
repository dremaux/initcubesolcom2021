#include <json.hpp>
#include "../include/GestionCommandes.h"
#include "../include/mongocxx.h"


// 
void GestionCommandes::transmettreDernieresCommandes(){

    cout << "" << endl;
}

// récupère les trames de la BDD 
void GestionCommandes::DernieresCommandes(int){
    
    mongocxx::instance instance{};
    mongocxx::client client{mongocxx::uri{}};

    mongocxx::database db = client["initcube"];
    mongocxx::collection coll = db["commande"];


    // affiche tout les éléments de la collection
    mongocxx::cursor cursor = coll.find({});
    for(auto doc : cursor) {
    cout << bsoncxx::to_json(doc) << endl;
}

}