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

int GestionInstrument::nettoyerInstruments()
{
  coll.drop();

  std::string ma_trame1=R"({"nom":"Camera infrarouge","identifiant":"123BCD","ref":"CamInfra","adresse":"0x69","role":"mesurer une temperature","listeTypesMesure":[{"nom":"temperature","code":"TC","description":"Température de l'objet mesuré","unite":"°C","valMax":"90","valMin":"-40"},{"nom":"matrice","code":"PIX","description":"Matrice d'une température de l'objet mesuré","unite":"°C","valMax":"90","valMin":"-40"}]})";
  std::string ma_trame2=R"({"nom":"Magnétomètre","identifiant":"124BCD","ref":"Magnetometre","adresse":"0x0C","role":"Mesurer un champ magnétique","listeTypesMesure":[{"nom":"BX","code":"BX","description":"Champ magnetique suivant X","unite":"μT","valMax":"100","valMin":"0"},{"nom":"BY","code":"BY","description":"Champ magnetique suivant Y","unite":"μT","valMax":"100","valMin":"0"},{"nom":"BZ","code":"BZ","description":"Champ magnetique suivant Z","unite":"μT","valMax":"100","valMin":"0"}]})";

  coll.insert_one(std::move(bsoncxx::from_json(ma_trame1)));
  coll.insert_one(std::move(bsoncxx::from_json(ma_trame2)));

}