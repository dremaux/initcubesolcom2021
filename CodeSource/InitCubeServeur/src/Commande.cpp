#include "Commande.hpp"


Commande::Commande(){

}

Commande::Commande(string tJson,int numeroCommande):trame(tJson){
    trame =R"({ "CMD": {
            "idSatellite": "1",
            "typeCommande": "MEASURE",
            "code": "TC"
            }
        })"_json;

    nCommande[0] = numeroCommande;
}

Commande::Commande(string tJson):trame(tJson){

}

Commande::~Commande() {
    
}

int Commande::extraireDonnees(){
    cout<<trame<<endl;
    if(trame.find("CMD") != trame.end() && trame["CMD"].find("idSatellite") != trame["CMD"].end() && trame["CMD"].find("typeCommande") != trame["CMD"].end()){
        id = trame["CMD"]["idSatellite"];
        cmd = trame["CMD"]["typeCommande"];
        if(cmd == "MISSION"){
            CMD = MISSION;
            extraireDonneesMis();
            return(1);
        }

        if(cmd == "MEASURE"){
            CMD = MEASURE;
            extraireDonneesMea();
            return(1);
        }

        if(cmd == "STATUS"){
            CMD = STATUS;
            extraireDonneesSta();
            return(1);
        }
    
        if(cmd == "DEPLOY"){
            CMD = DEPLOY;
            return(1);
        }

        if(cmd == "SURVIVAL"){
            CMD = SURVIVAL;
            return(1);
        }

        if(cmd == "EMPTY"){
            CMD = EMPTY;
            return(1);
        }

        if(cmd == "SAVE"){
            CMD = SAVE;
            return(1);
        }

        if(cmd == "MEETING"){
            CMD = MEETING;
            extraireDonneesMee();
            return(1);
        }

        if(cmd == "DATE"){
            CMD = DATE;
            return(1);
        }
    }
    else{
        cout<<"trame non conforme"<<endl;
        return(-1);
    }
}

void Commande::extraireDonneesMis(){
    if(trame["CMD"].find("PERIODE") != trame["CMD"].end()){
        periode = trame["CMD"]["PERIODE"];
        periode = "-P"+ periode;
    }

    if(trame["CMD"].find("DUREE") != trame["CMD"].end()){
        duree =trame["CMD"]["DUREE"];
        duree = "-D"+ duree;
    }

    if(trame["CMD"].find("DATE") != trame["CMD"].end()){
        date =trame["CMD"]["DATE"];
        date = "-DT"+ date;
    }

    if(trame["CMD"].find("SAVE") != trame["CMD"].end()){
        save = "-SAVE";
    }

    if(trame["CMD"].find("code") != trame["CMD"].end()){
        typeMeasure = trame["CMD"]["code"];
        typeMeasure = "-" + typeMeasure;
    }
}

void Commande::extraireDonneesMea(){
    if(trame["CMD"].find("code") != trame["CMD"].end()){
        typeMeasure = trame["CMD"]["code"];
        typeMeasure = "-" + typeMeasure;
    }
}

void Commande::extraireDonneesSta(){
    if(trame["CMD"].find("PERIODE") != trame["CMD"].end()){
        periode = trame["CMD"]["PERIODE"];
        periode = "-P"+ periode;
    }

    if(trame["CMD"].find("DUREE") != trame["CMD"].end()){
        duree =trame["CMD"]["DUREE"];
        duree = "-D"+ duree;
    }

    if(trame["CMD"].find("BORD") != trame["CMD"].end()){
        bord = "-BORD";
    }
    

    if(trame["CMD"].find("INST") != trame["CMD"].end()){
        inst = "-INST";
    }
    

    if(trame["CMD"].find("BATT") != trame["CMD"].end()){
        batt = "-BATT";
    }
    

    if(trame["CMD"].find("REBOOT") != trame["CMD"].end()){
        reboot = "-REBOOT";
    }
    
    if(trame["CMD"].find("CUBE") != trame["CMD"].end()){
        cube = "-CUBE";
    }
    

}

void Commande::extraireDonneesMee(){
    if(trame["CMD"].find("DUREE") != trame["CMD"].end()){
        duree =trame["CMD"]["DUREE"];
        duree = "-D"+ duree;
    }

    if(trame["CMD"].find("DATE") != trame["CMD"].end()){
        date =trame["CMD"]["DATE"];
        date = "-DT"+ date;
    }

    if(trame["CMD"].find("SAVE") != trame["CMD"].end()){
        save = "-SAVE";
    }
}

void Commande::extraireDonneesDat(){
    if(trame["CMD"].find("DATE") != trame["CMD"].end()){
        date =trame["CMD"]["DATE"];
        date = "-DT"+ date;
    }
}

string Commande::genererTrame(){
    string trameInter;
    switch (CMD)
    {
    
    case MISSION:
        trameInter = cmd + periode + duree + date + typeMeasure + save;
        break;
    
    case MEASURE:
        trameInter = cmd + typeMeasure;
        
        break;
    
    case STATUS:
        trameInter = cmd + bord + inst + batt + reboot + cube + periode + duree;
        break;
    
    case DEPLOY:
        trameInter = cmd;
        break;
    
    case SURVIVAL:
        trameInter = cmd;
        break;
    
    case EMPTY:
        trameInter = cmd;
        break;
    
    case SAVE:
        trameInter = cmd;
        break;
    
    case MEETING:
        trameInter = cmd + date + duree + save;
        break;
    
    case DATE:
        trameInter = cmd;
        break;
    
    default:
        cout<<"problème de trame"<<endl;
        return 0;
        break;
    }
    nbOctets = trameInter.length();
    trameInter = "~  " + trameInter ; //les trois espace sont pour 255(caractere de debut), l'id et pour le nombre d'octets dans le payload 

    char trameF[trameInter.length()+3];

    strcpy(trameF, trameInter.c_str());
    trameF[1] = stoi(id,nullptr);
    trameF[2] = nbOctets;
    trameF[trameInter.length()+2] = 255;
    calculerChecksum(trameF,trameF[trameInter.length()],trameF[trameInter.length()+1]);
    testAfficherTrame(trameInter,trameF);

    string s(trameF);
    return s;


}

void Commande::calculerChecksum( char* trameF, char & PF,  char & pf){
    short Checksum=0;
    char leChecksum[2];

    for (int i=1;i<nbOctets+3;i++)
    {
        Checksum=Checksum^trameF[i];
    }
    sprintf(leChecksum, "%2X",Checksum);
    if (leChecksum[0]==32) leChecksum[0]='0';
    if (leChecksum[1]==32) leChecksum[1]='0';
    PF = leChecksum[0];
    pf = leChecksum[1];

}

void Commande::testAfficherTrame(string trameInter,  char* trameF){
    for(int i = 0;i<trameInter.length()+3;i++){
        cout<<trameF[i];
    }
    cout<<(int)trameF[1]<<" "<<(int)trameF[2]<<endl;
    cout<<trameInter<<endl;
}

bool Commande::setTrame(string trame){
    try{
        this->trame = json::parse(trame);
        return true;
    }
    catch(exception e){
        cout<<"trame reçu non JSON"<<endl;
        return false;
    }
    
    
}
