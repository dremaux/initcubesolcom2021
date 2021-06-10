#include <iostream>
#include <string>
#include "gCommandes.h"

using namespace std;

int main()
{

    mongocxx::instance instance{};
    GestionCommandes *gCommandes = new GestionCommandes();

    //cout << "Content-Type: text/html\r\n\r\n";

    std::string ma_trame=R"({ "CMD" : {"idSatellite":"1", "typeCommande":"MEASURE", "refInstrument":"CamInfra", "code":"TC", "dateEnvoi":"0000/00/00 00:00:00", "reponse": "non" }})";
    gCommandes->stockerCommande(ma_trame);
    cout << "ok" << endl;

/*
    std::string nombre = "";
    nombre = getenv("QUERY_STRING");
    if (nombre.empty())
    {
        gCommandes->getDernieresCommandes();
    }
    else
    {
        gCommandes->getDernieresCommandes(std::stoi(nombre));
    }
    gCommandes->transmettreCommandes();
*/ 

/*
    std::string date; 
    std::getline(std::cin,date);
    gCommandes->rechercherCommandesParDate(date);
*/

/*
    std::string ma_reponse;
    ma_reponse = R"({"measure":{"code":"TC","donnee":["36.7","35.4"],"nom":"temperature","unite":"°C"}})";
    gCommandes->ajouterReponse(json::parse(ma_reponse));
    cout << "ok" << endl;
*/
    return 0;
}
