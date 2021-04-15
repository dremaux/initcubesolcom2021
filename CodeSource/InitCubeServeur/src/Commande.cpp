#include "Commande.hpp"



Commande::Commande(string tJson,int numeroCommande):trame(tJson){
    trame =R"({ "CMD": {
            "ID": "1",
            "TYPE": "MEASURE",
            "TYPEMEASURE": "TC"
            }
        })"_json;

    nCommande[0] = numeroCommande;
}

Commande::Commande(string tJson):trame(tJson){
    trame =R"({ "CMD": {
            "ID": "1",
            "TYPE": "MEASURE",
            "TYPEMEASURE": "PIX",
            "PERIODE": "10",
            "DATE": "2021/03/10 15:55:30"
            }
        })"_json;
}

Commande::~Commande() {
    
}

void Commande::extraireDonnees(){
    if(trame.find("CMD") != trame.end() && trame["CMD"].find("ID") != trame["CMD"].end() && trame["CMD"].find("TYPE") != trame["CMD"].end()){
        id = trame["CMD"]["ID"];
        cmd = trame["CMD"]["TYPE"];
        if(cmd == "MISSION"){
            CMD = MISSION;
            extraireDonneesMis();
        }

        if(cmd == "MEASURE"){
            CMD = MEASURE;
            extraireDonneesMea();
        }

        if(cmd == "STATUS"){
            CMD = STATUS;
            extraireDonneesSta();
        }
    
        if(cmd == "DEPLOY"){
            CMD = DEPLOY;
            
        }

        if(cmd == "SURVIVAL"){
            CMD = SURVIVAL;
           
        }

        if(cmd == "EMPTY"){
            CMD = EMPTY;
            
        }

        if(cmd == "SAVE"){
            CMD = SAVE;
           
        }

        if(cmd == "MEETING"){
            CMD = MEETING;
            extraireDonneesMee();
        }

        if(cmd == "DATE"){
            CMD = DATE;
            
        }
    }
    else{
        cout<<"trame non conforme"<<endl;
        
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

    if(trame["CMD"].find("TYPEMEASURE") != trame["CMD"].end()){
        typeMeasure = trame["CMD"]["TYPEMEASURE"];
        typeMeasure = "-" + typeMeasure;
    }
}

void Commande::extraireDonneesMea(){
    if(trame["CMD"].find("TYPEMEASURE") != trame["CMD"].end()){
        typeMeasure = trame["CMD"]["TYPEMEASURE"];
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
        trameInter = cmd + date + duree;
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
    trameInter = "   " + trameInter ; //les trois espace sont pour 255(caractere de debut), l'id et pour le nombre d'octets dans le payload 
    
    unsigned char trameF[trameInter.length()+3];
    memcpy(trameF,trameInter.c_str(),trameInter.length());
    trameF[0] = '~';
    trameF[1] = stoi(id,nullptr);
    trameF[2] = nbOctets;
    trameF[trameInter.length()+2] = 255;
    calculerChecksum(trameF,trameF[trameInter.length()],trameF[trameInter.length()+1]);
    //testAfficherTrame(trameInter,trameF);
    string s(reinterpret_cast<char*>(trameF));
    return s;


}

void Commande::calculerChecksum(unsigned char* trameF,unsigned char & PF, unsigned char & pf){
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

void Commande::testAfficherTrame(string trameInter, char* trameF){
    for(int i = 0;i<trameInter.length()+3;i++){
        cout<<trameF[i];
    }
    cout<<(int)trameF[1]<<" "<<(int)trameF[2]<<endl;
    cout<<trameInter<<endl;
}

void Commande::setTrame(string trame){
    this->trame = trame; 
}