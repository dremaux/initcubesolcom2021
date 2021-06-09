#include "gCommandes.h"

GestionCommandes::GestionCommandes()
{
  db = client["initcube"];
  coll = db["commande"];
}

int GestionCommandes::getDernieresCommandes(int nombre)
{
  this->commandes.clear();

  mongocxx::options::find opts;
  opts.sort(make_document(kvp("CMD.dateEnvoi", -1))).limit(nombre);
  auto cursor = coll.find({}, opts);

  int nombreCommandes = 0;

  for (auto doc : cursor)
  {
    this->commandes.push_back(to_json(doc));
    nombreCommandes++;
  }
  return nombreCommandes;
}

int GestionCommandes::rechercherCommandesParDate(std::string date)
{
  bsoncxx::builder::stream::document document{};
  document << "CMD.dateEnvoi" << bsoncxx::types::b_regex{"^" + date};
  auto cursor = coll.find(document.view());                                            

  for (auto doc : cursor)
  {
    cout << to_json(doc) << endl;
  }
  return 0;
}

int GestionCommandes::transmettreCommandes()
{
  int nbreCommandesTransmises = 0;
  for (int i = 0; i < commandes.size()-1; i++)
  {
    cout << commandes[i] << endl;
    nbreCommandesTransmises++;
  }
  cout << commandes[commandes.size()-1];
  nbreCommandesTransmises++;
  return nbreCommandesTransmises;
}

int GestionCommandes::stockerCommande(std::string laCommande)
{
  
  //std::string::laCommande = json::parse(commande);
  
  json::parse(laCommande);

  time_t rawtime;
  struct tm * timeinfo;
  char buffer [80];

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer,80,"%Y/%m/%d %H:%M:%S",timeinfo);
  puts (buffer);                                          

  commande["CMD"]["dateEnvoi"] = buffer;                
    coll.insert_one(std::move(bsoncxx::from_json(commande)));
}

int GestionCommandes::ajouterReponse(std::string laReponse)
{
  json::parse(laReponse);
  coll.update_one(make_document ( kvp("CMD.reponse","non")),        
  make_document(kvp("$set",make_document(kvp("CMD.reponse", bsoncxx::from_json(laReponse))))));
}