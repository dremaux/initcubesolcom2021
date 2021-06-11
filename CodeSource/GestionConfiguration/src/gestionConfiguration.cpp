#include "gConfiguration.h"

// connection à la BDD "initcube" et à la collection "segmentVol"
GestionConfiguration::GestionConfiguration()
{
  db = client["initcube"];
  coll = db["segmentVol"];
}

//recherche la dernière trame enregistrer dans la BDD
int GestionConfiguration::restituerDerniereConfiguration()
{
  mongocxx::options::find opts;
  opts.sort(make_document(kvp("dateEnvoi", -1))).limit(1); // trie les trames par ordre décroissant en fonction des dateEnvoi, et en affiche qu'une 
  auto cursor = coll.find({}, opts);

  for (auto doc : cursor)
  {
    this->configuration=to_json(doc);
  }
}

//affiche les trames reçu, fonctionne avec "restituerDernièreConfiguration"
int GestionConfiguration::transmettreConfiguration()
{
  cout << this->configuration << endl;
  return 1;
}

//ajout la date et stocke la trame reçu dans la BDD
int GestionConfiguration::stockerConfiguration(std::string config)
{
  json laConfig = json::parse(config);
  time_t rawtime;
  struct tm * timeinfo;
  char buffer [80];

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer,80,"%Y/%m/%d %H:%M:%S",timeinfo);

  laConfig["CMD"]["dateEnvoi"] = buffer;
  
    coll.insert_one(std::move(bsoncxx::from_json(laConfig.dump())));
}