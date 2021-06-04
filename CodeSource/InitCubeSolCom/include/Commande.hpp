#pragma once
#include "Lib.h"
#include "Cmd.h"

using namespace std;


class Commande {

public:
    Commande();
    Commande(string json,int numeroCommande);
    Commande(string json);
    ~Commande();
    int extraireDonnees();
    bool genererTrame(unsigned char* trameF);
    bool setTrame(string trame);


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
    string id;
    string cmd;
    string periode;
    string duree;
    string date;
    string ack;
    string bord;
    string inst;
    string batt;
    string reboot;
    string cube;
    string typeMeasure;
    string save;
    int nbOctets;
};