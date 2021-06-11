#include <iostream>
#include <string>
#include "gCommandes.h"

using namespace std;

int main()
{

    mongocxx::instance instance{};
    GestionCommandes *gCommandes = new GestionCommandes();
    int a;

    //cout << "Content-Type: text/html\r\n\r\n";


    std::string ma_trame=R"({ "CMD" : {"idSatellite":"1", "typeCommande":"MEASURE", "refInstrument":"CamInfra", "code":"TC", "dateEnvoi":"0000/00/00 00:00:00", "reponse": "non" }})";
    gCommandes->stockerCommande(ma_trame);
    cout << "commande stocker" << endl;

    cout << "saisissez 1 pour contuinuer" << endl;
    cin >> a;

    std::string ma_reponse;
    ma_reponse = R"({"mesure":{"code":"TC","donnees":["36.7"],"type":"normal","unite":"°C"}})";
    gCommandes->ajouterReponse(ma_reponse);
    cout << "reponse stocker" << endl;

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

    //gCommandes->nettoyerCommandes();



    return 0;
}
