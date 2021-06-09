#include "gCommandes.h"

// connection à la base de données "initcube" et à la collection "commande"
GestionCommandes::GestionCommandes()
{
  db = client["initcube"];
  coll = db["commande"];
}

//renvoie les dernières commandes enregister dans la base de données
//en fonction du chiffre qui est attribué à "nombre"
int GestionCommandes::getDernieresCommandes(int nombre)
{
  this->commandes.clear();

  mongocxx::options::find opts;
  opts.sort(make_document(kvp("CMD.dateEnvoi", -1))).limit(nombre); //"-1" = ordre décroissant 
  auto cursor = coll.find({}, opts);

  int nombreCommandes = 0;

  for (auto doc : cursor)
  {
    this->commandes.push_back(to_json(doc));
    nombreCommandes++;
  }
  return nombreCommandes;
}

//affiche toutes les commandes qui ont la "date" qui lui sera attribuer
int GestionCommandes::rechercherCommandesParDate(std::string date)
{
  bsoncxx::builder::stream::document document{};
  document << "CMD.dateEnvoi" << bsoncxx::types::b_regex{"^" + date}; //cherche dans les valeurs de la BDD, la valeur attribué à "date"
  auto cursor = coll.find(document.view());                           //il peut couper une valeur d'une clée               
                       
  for (auto doc : cursor)
  {
    cout << to_json(doc) << endl;
  }
  return 0;
}

//compte et cout les trames pour getDerniereCommande
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

//stocke les trames reçu et ajoute une date à la trames
int GestionCommandes::stockerCommande(std::string laCommande)
{
  json commande;
  std::string laCommande = json::parse(commande);
  
  time_t rawtime;
  struct tm * timeinfo;
  char buffer [80];

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer,80,"%Y/%m/%d %H:%M:%S",timeinfo);
  puts (buffer);  // stocke la date de la machine dans buffer sous forme yyyy/mm/jj hh/mm/ss                                        

  commande["CMD"]["dateEnvoi"] = buffer; // on stocke la date dans dateEnvoi               
    coll.insert_one(std::move(bsoncxx::from_json(commande)));
}

//ajoute la reponse à la trame qui lui correspond
int GestionCommandes::ajouterReponse(std::string laReponse)
{
  json::parse(laReponse);
  coll.update_one(make_document ( kvp("CMD.reponse","non")), // on cherche une trame avec comme clée = reponse et valeur de la clée = "non"
                                                             // comme la commande c'est update_one il modifie une seul trames et il prend 
                                                             // la première trames qu'il voie, soit celle qui à la date la plus ancienne        
  make_document(kvp("$set",make_document(kvp("CMD.reponse", bsoncxx::from_json(laReponse)))))); // modifie dans le champ réponse de la trame la valeur 
                                                                                                // et on ajoute la valeur attribué à "laReponse"
}