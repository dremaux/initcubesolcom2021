#include "gInstrument.h"

GestionInstrument::GestionInstrument()
{
  db = client["initcube"];
  coll = db["instrument"];
}

int GestionInstrument::getListeInstruments(int nombre)
{
  this->instruments.clear();

  mongocxx::options::find opts;
  opts.limit(nombre);
  auto cursor = coll.find({}, opts);

  int nombreInstruments = 0;

  for (auto doc : cursor)
  {
    this->instruments.push_back(to_json(doc));
    nombreInstruments++;
  }
  return nombreInstruments;
}

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

int GestionInstrument::stockerInstrument(json instrument)
{
  
  coll.insert_one(std::move(from_json(instrument.dump())));
  //coll.insert_one(from_json(instrument));
    
}