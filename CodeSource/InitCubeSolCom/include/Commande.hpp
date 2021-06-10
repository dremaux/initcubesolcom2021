#pragma once
#include "Lib.h"
#include "Cmd.h"

using namespace std;


class Commande {

public:
    Commande();
    Commande(std::string json,int numeroCommande);
    Commande(std::string json);
    ~Commande();
    int extraireDonnees();
    bool genererTrame(unsigned char* trameF);
    bool setTrame(std::string trame);


private:
    void calculerChecksum( unsigned char* trameF, unsigned char & PF, unsigned char & pf);
    void extraireDonneesMis();
    void extraireDonneesMea();
    void extraireDonneesSta();
    void extraireDonneesMee();
    void extraireDonneesDat();
    char nCommande[1];
    Cmd CMD;
    nlohmann::json trame;
    std::string id;
    std::string cmd;
    std::string periode;
    std::string duree;
    std::string date;
    std::string ack;
    std::string bord;
    std::string inst;
    std::string batt;
    std::string reboot;
    std::string cube;
    std::string typeMeasure;
    std::string save;
    int nbOctets;
};