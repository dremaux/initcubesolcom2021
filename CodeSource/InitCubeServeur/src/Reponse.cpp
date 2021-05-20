#include "Reponse.hpp"

Reponse::Reponse() {
    measure = new Measure();
    status = new Status();
    mission = new Mission();
    trame = "";
}

string Reponse::identifierType(){
    if(trame.find("MISSION") < trame[2]+2){
        mission->setTrame(trame);
        mission->identifierType();
        return "JSON";
    }
    else if(trame.find("MEASURE") < trame[2]+2){
        measure->setTrame(trame);
        measure->identifierType();
        return "JSON";
    }
    else if(trame.find("STATUS") < trame[2]+2){
        status->extraireDonnee(trame);
        return "JSON";
    }
    else if(trame.find("HELLO") < trame[2]+2){
        return "ACK";
    }
    else if(trame.find("OK") < trame[2]+2){
        return "ACK";
    }
    else if(trame.find("FAIL") < trame[2]+2){
        return "ACK";
    }
    else if(trame.find("BUSY") < trame[2]+2){
        return "ACK";
    }
    else if(trame.find("NACK") < trame[2]+2){
        return "ACK";
    }
    else if(trame.find("ACK") < trame[2]+2){
        return "ACK";
    }
    else if(trame.find("ERROR-E") < trame[2]+2){
        return "ACK";
    }
    else{
        cout<<"trame non conforme"<<endl;
        return "error";
    }
}

string Reponse::genererTrame(){
    string retour;
    if(trame.find("MISSION") < trame[2]+2){
        retour = mission->genererTrame();
        return retour;
    }
    else if(trame.find("MEASURE") < trame[2]+2){
        retour = measure->genererTrame();
        return retour;
    }
    else if(trame.find("STATUS") < trame[2]+2){
        retour = status->genereTrame();
        return retour;
    }
    else{
        cout<<"trame mauvaise ou ne nécessite pas de reponse"<<endl;
        return "error";
    }
}

Reponse::~Reponse() {

}