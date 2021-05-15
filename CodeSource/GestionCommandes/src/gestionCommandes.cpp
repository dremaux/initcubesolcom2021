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

#include "gCommandes.h"
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

GestionCommandes::GestionCommandes()
{
  //choix de la base de donneés (initcube) et de la collection (commande)
  db = client["initcube"];
  coll = db["commande"];
}

//getDernieresCommandes() prend en paramètre le nombre de commandes souhaitées
int GestionCommandes::getDernieresCommandes(int nombre)
{
  //on réinitialise le tableau des dernières commandes
  this->commandes.clear();

  //on prépare le filtre de recherche
  mongocxx::options::find opts;
  opts.sort(make_document(kvp("CMD.DATE", -1))).limit(nombre);

  //on effectue la requête et on stocke le résultat dans cursor
  auto cursor = db["commande"].find({}, opts);
  //int nombreCommandes = cursor.size();

  //initialisation de la variable permettant de compter le nombre de commandes reçues
  int nombreCommandes = 0;
  //on traite le résultat de la requête
  for (auto doc : cursor)
  {
    //pour chaque nouvelle commande trouvée, on l'ajoute au tableau des commandes (push_back())
    this->commandes.push_back(to_json(doc));
    //On incrémente le nombre de commandes
    nombreCommandes++;
  }
  return nombreCommandes;
}

int GestionCommandes::rechercherCommandesParDate(std::string date)
{
  this->commandes.clear();
  bsoncxx::builder::stream::document document{};
  //On recherche les enregistrements possédant la date passée en paramètre de la méthode (utilisation des expressions régulières)
  document << "CMD.DATE" << bsoncxx::types::b_regex{"^"+date}; 
  auto cursor = coll.find(document.view());
  //autre façon de faire la requête
  //auto cursor = coll.find(make_document(kvp("CMD.DATE", bsoncxx::types::b_regex{"^"+date})));
  int nombreCommandes = 0;
  for (auto doc : cursor){
    //pour chaque nouvelle commande trouvée, on l'ajoute au tableau des commandes (push_back())
    this->commandes.push_back(to_json(doc));
    //On incrémente le nombre de commandes
    nombreCommandes++;
  }
  return nombreCommandes;
}

int GestionCommandes::transmettreCommandes()
{
  int nbreCommandesTransmises = 0;
  for (int i = 0;i<commandes.size();i++) {
    cout << commandes[i] <<endl;
    nbreCommandesTransmises++;
  }
  return nbreCommandesTransmises;
}