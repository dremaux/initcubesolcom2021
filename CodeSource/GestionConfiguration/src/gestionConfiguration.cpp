#include "gConfiguration.h"


GestionConfiguration::GestionConfiguration()
{
  db = client["initcube"];
  coll = db["segmentVol"];
}

int GestionConfiguration::retituerDerniereConfiguration()
{
  this->configurations.clear();

  mongocxx::options::find opts;
  opts.sort(make_document(kvp("DATE", -1))).limit(1);
  auto cursor = coll.find({}, opts);

  for (auto doc : cursor)
  {
    this->configurations.push_back(to_json(doc));
  }
  
}

int GestionConfiguration::transmettreConfiguration()
{
  int nbreConfigurationTransmises = 0;
  for (int i = 0; i < configurations.size()-1; i++)
  {
    cout << configurations[i] << endl;
    nbreConfigurationTransmises++;
  }
  cout << configurations[configurations.size()-1];
  nbreConfigurationTransmises++;
  return nbreConfigurationTransmises;
}

int GestionConfiguration::stockerConfiguration(json laConfig)
{
  time_t rawtime;
  struct tm * timeinfo;
  char buffer [80];

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer,80,"%Y/%m/%d %H:%M:%S",timeinfo);
  puts (buffer);

  laConfig["CMD"]["DATE"] = buffer;

    coll.insert_one(std::move(bsoncxx::from_json(laConfig)));
}
