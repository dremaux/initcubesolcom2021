#include "gConfiguration.h"

GestionConfiguration::GestionConfiguration()
{
  db = client["initcube"];
  coll = db["segmentVol"];
}

int GestionConfiguration::restituerDerniereConfiguration()
{
  //this->configuration.clear();

  mongocxx::options::find opts;
  opts.sort(make_document(kvp("dateEnvoi", -1))).limit(1); 
  auto cursor = coll.find({}, opts);

  for (auto doc : cursor)
  {
    this->configuration=to_json(doc);
  }
}

int GestionConfiguration::transmettreConfiguration()
{
  cout << this->configuration << endl;
  return 1;
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

  laConfig["CMD"]["dateEnvoi"] = buffer;

    coll.insert_one(std::move(bsoncxx::from_json(laConfig)));
}
