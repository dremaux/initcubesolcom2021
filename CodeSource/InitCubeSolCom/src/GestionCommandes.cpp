#include "GestionCommandes.h"

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
int GestionCommandes::stockerCommande(std::string commande)
{
  json laCommande = json::parse(commande);
  time_t rawtime;
  struct tm * timeinfo;
  char buffer [80];

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer,80,"%Y/%m/%d %H:%M:%S",timeinfo);                                        

  laCommande["CMD"]["dateEnvoi"] = buffer;                
    coll.insert_one(std::move(bsoncxx::from_json(laCommande.dump())));
}

//ajoute la reponse à la trame qui lui correspond
int GestionCommandes::ajouterReponse(std::string laReponse)
{
  std::string typeCommande, codeCommande;
  
if(laReponse.find("status")!=std::string::npos){      // je recherhce dans la trame si il y a "status" à l'interieur.

  json reponseParse = json::parse(laReponse);
  typeCommande = "STATUS";

  coll.update_one(make_document ( kvp("CMD.reponse","non"), kvp("CMD.typeCommande",typeCommande)),
  make_document(kvp("$set",make_document(kvp("CMD.reponse", bsoncxx::from_json(reponseParse.dump())))))); 


}else if(laReponse.find("mesure")!=std::string::npos){
  json reponseParse = json::parse(laReponse);
  typeCommande = "MEASURE";                       // typeCommande prend la valeur "MEASURE"
  codeCommande = reponseParse["mesure"]["code"];  // codeCommande prend la valeur de la reponce envoyer, qui ce citue dans "mesure":{"code":"....."}

  coll.update_one(make_document ( kvp("CMD.reponse","non"), kvp("CMD.typeCommande",typeCommande), kvp("CMD.code",codeCommande)), // on cherche une commande dans la BDD avec valeur de reponse = non, typeCommande = (la variable de typeCommande), code = codeCommande 
  make_document(kvp("$set",make_document(kvp("CMD.reponse", bsoncxx::from_json(reponseParse.dump())))))); // puis on rajout la trame 


  }else if(laReponse.find("mission")!=std::string::npos){
  json reponseParse = json::parse(laReponse);
  typeCommande = "MISSION";
  codeCommande = reponseParse["mission"]["code"];

  coll.update_one(make_document ( kvp("CMD.reponse","non"), kvp("CMD.typeCommande",typeCommande), kvp("CMD.code",codeCommande)),
  make_document(kvp("$set",make_document(kvp("CMD.reponse", bsoncxx::from_json(reponseParse.dump())))))); 
  
  }else return -1;
}