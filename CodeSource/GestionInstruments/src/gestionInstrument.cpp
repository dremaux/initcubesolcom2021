#include "gInstrument.h"

//connection à la BDD "initcube" et à la collection "instrument"
GestionInstrument::GestionInstrument()
{
  db = client["initcube"];
  coll = db["instrument"];
}

//recherche tout les trames enregistrer dans la BDD
int GestionInstrument::getListeInstruments(int nombre)
{
  this->instruments.clear();

  mongocxx::options::find opts;
  opts.limit(nombre);                 // si nombre = 0 alors affiche toutes les trames
  auto cursor = coll.find({}, opts);

  int nombreInstruments = 0;

  for (auto doc : cursor)
  {
    this->instruments.push_back(to_json(doc));
    nombreInstruments++;
  }
  return nombreInstruments;
}

//affiche les trames touvée grâce à getListeInstruments
int GestionInstrument::transmettreInstruments()
{
  int nbreInstrumentsTransmises = 0;
  for (int i = 0; i < instruments.size()-1; i++)
  {
    cout << instruments[i] << endl;
    nbreInstrumentsTransmises++;
  }
  cout << instruments[instruments.size()-1];
  nbreInstrumentsTransmises++;
  return nbreInstrumentsTransmises;
}

//stocke les trames reçu
int GestionInstrument::stockerInstrument(std::string instrument)
{
  coll.insert_one(std::move(bsoncxx::from_json(instrument)));
}