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
  mongocxx::instance instance{};
  mongocxx::client client{mongocxx::uri{}};

  mongocxx::database db = client["initcube"];
  mongocxx::collection coll = db["commande"];
}

int GestionCommandes::getDerniereCommandes()
{

  mongocxx::options::find opts;
  opts.sort(make_document(kvp("CMD.DATE", -1))).limit(3);

  auto cursor = db["commande"].find({}, opts);
  for (auto &&doc : cursor)
  {
    cout << to_json(doc) << endl;
  }
  return nombreCommandes;
}

int GestionCommandes::rechercheCommandes()
{

  bsoncxx::builder::stream::document document{};
  document << "CMD.DATE" << 3; // on précise ce que l'on cherche
  auto cursor = coll.find(document.view());

  for (auto &&doc : cursor)
  {
    cout << to_json(doc) << endl;
  }
  return DerniereCommandes;
}

int GestionCommandes::tDCommandes()
{
  return 0;
}