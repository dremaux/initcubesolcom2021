#include "../include/gCommandes.h"

GestionCommandes::GestionCommandes(){
  //gestionCommandes = new GestionCommandes;
}

int GestionCommandes::getDCommandes(int getDernieresCommandes){

mongocxx::options::find opts;
opts.sort(make_document(kvp("CMD.DATE", -1), kvp("CMD.DATE", -1))).limit( 3 );

auto cursor = db["commande"].find({}, opts, opt);
for (auto&& doc : cursor) {
  std::cout << bsoncxx::to_json(doc) << std::endl;
}

}




int GestionCommandes::rechercheCommandes(int date){

nombreDC = date;
bsoncxx::builder::stream::document document{};
document<<"CMD.DATE"<<nombreDC;  // on précise ce que l'on cherche
auto cursor = coll.find(document.view());

for (auto&& doc : cursor){
cout << bsoncxx::to_json(doc) << endl; 
}

}


int GestionCommandes::tDCommandes(){
return 0;
}
