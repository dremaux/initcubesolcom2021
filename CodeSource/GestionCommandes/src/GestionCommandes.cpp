#include "json.hpp"
#include "GestionCommandes.h"
#include "mongocxx.h"

// récupère les trames de la BDD 
void GestionCommandes::DCommandes(int){
    
//on trouve l'info
int mongocxx::cursor cursor = coll.find({"CMD.DATE": { $gt:"16"}});
    for(auto doc : cursor) {
        cout << bsoncxx::to_json(doc) << endl;
    }

return DCommandes;
}


// fait un Cout de derniereCommandes
void GestionCommandes::transmettreDernieresCommandes(){

    cout << "" << endl;
}


}