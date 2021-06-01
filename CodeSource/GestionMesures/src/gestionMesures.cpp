#include "gMesures.h"

GestionCommandes::GestionCommandes()
{
  db = client["initcube"];
  coll = db["commande"];
}


int GestionCommandes::stockerCommande(json laCommande)
{
  
  time_t rawtime;
  struct tm * timeinfo;
  char buffer [80];

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer,80,"%Y/%m/%d %H:%M:%S",timeinfo);
  puts (buffer);

  laCommande["DATE"] = buffer;

      coll.insert_one(std::move(from_json(laCommande.dump())));
}