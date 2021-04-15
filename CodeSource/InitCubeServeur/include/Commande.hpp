#pragma once
#include "Lib.h"
#include "Cmd.h"

using namespace std;
using json = nlohmann::json;

class Commande {

public:
    Commande(string json,int numeroCommande);
    Commande(string json);
    ~Commande();
    void extraireDonnees();
    string genererTrame();
    void setTrame(string trame);


private:
    void calculerChecksum(unsigned char* trameF,unsigned char & PF,unsigned char & pf);
    void extraireDonneesMis();
    void extraireDonneesMea();
    void extraireDonneesSta();
    void extraireDonneesMee();
    void extraireDonneesDat();
    void testAfficherTrame(string trameInter, char* trameF); //affiche la trame pour tester si elle est juste (a mettre avant le return de genererTrame)
    char nCommande[1];
    Cmd CMD;
    json trame;
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