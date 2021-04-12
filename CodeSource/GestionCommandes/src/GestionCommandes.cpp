#include "../include/GestionCommandes.h"
#include "../include/mongocxx.h"

// récupère les trames de la BDD 
int GestionCommandes::DCommandes(int){
    
//on trouve l'info
int mongocxx::cursor cursor = coll.find({"CMD.DATE": { $gt:"15"}});
    for(auto doc : cursor) {
        cout << bsoncxx::to_json(doc) << endl;
    }

return DCommandes;
}


// fait un Cout de derniereCommandes
void GestionCommandes::TDCommandes(){

    cout << "" << endl;
}


}