#include <../include/json.hpp>
#include "../include/GestionCommandes.h"
#include "../include/mongocxx.h"


// fait un Cout de derniereCommandes
void GestionCommandes::transmettreDernieresCommandes(){

    cout << "" << endl;
}

// récupère les trames de la BDD 
void GestionCommandes::DernieresCommandes(int){
    

   mongocxx::cursor cursor = coll.find({"CMD.DATE": "16"});
for(auto doc : cursor) {
cout << bsoncxx::to_json(doc) << endl;
}


}

}