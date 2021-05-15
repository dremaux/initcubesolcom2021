#include "Status.hpp"

Status::Status() {
    compteur = 1;
    security = true;
    bord = false;
    SMo = "";
    Rp = "";
    DTb = "";
    Tbord = "";
    inst = false;
    marche = "";
    erreur = false;
    modeExp = "";
    Tinst = "";
    batt = false;
    C = "";
    V = "";
    A = "";
    load = "";
    Tbatt = "";
    reboot = false;
    DTr = "";
    N = "";
    cube = false;
    Tcube = "";
}

void Status::extraireDonnee(string trame){
    if(trame[NUM_TRAME] == compteur){
        security = false;
        compteur++;
        caseFinP = trame[2]+3;
        if(trame[NUM_TRAME] == 1){
            bord = false;
            SMo = "";
            Rp = "";
            DTb = "";
            Tbord = "";
            inst = false;
            marche = "";
            erreur = false;
            modeExp = "";
            Tinst = "";
            batt = false;
            C = "";
            V = "";
            A = "";
            load = "";
            Tbatt = "";
            reboot = false;
            DTr = "";
            N = "";
            cube = false;
            Tcube = "";    
        }

        if(trame.find("-BORD") < caseFinP){
            bord = true;

            if(trame.find("-SMo") < caseFinP){
                (trame.find("-",trame.find("-BORD")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-BORD")+1) : finChamp = caseFinP;
                SMo = trame.substr(trame.find("-SMo")+4,finChamp - trame.find("-BORD"));
            }

            if(trame.find("-R%") < caseFinP){
                (trame.find("-",trame.find("-SMo")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-SMo")+1) : finChamp = caseFinP;
                Rp = trame.substr(trame.find("-R%")+3,finChamp - trame.find("-SMo"));
            }

            if(trame.find("-T") < caseFinP){
                (trame.find("-",trame.find("-R%")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-R%")+1) : finChamp = caseFinP;
                Tbord = trame.substr(trame.find("-T")+2,finChamp - trame.find("-R%"));
            }

            if(trame.find("-DT") < caseFinP){
                (trame.find("-",trame.find("-T")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-T")+1) : finChamp = caseFinP;
                DTb = trame.substr(trame.find("-DT")+3,finChamp - trame.find("-T"));
            }
        }

        if(trame.find("-BATT") < caseFinP){
            batt = true;

            if(trame.find("-C") < caseFinP){
                (trame.find("-",trame.find("-BATT")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-BATT")+1) : finChamp = caseFinP;
                C = trame.substr(trame.find("-C")+2,finChamp - trame.find("-BATT"));
            }

            if(trame.find("-V") < caseFinP){
                (trame.find("-",trame.find("-C")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-C")+1) : finChamp = caseFinP;
                V = trame.substr(trame.find("-V")+2,finChamp - trame.find("-C"));
            }

            if(trame.find("-A") < caseFinP){
                (trame.find("-",trame.find("-V")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-V")+1) : finChamp = caseFinP;
                A = trame.substr(trame.find("-C")+2,finChamp - trame.find("-V"));
            }

            if(trame.find("-LOAD") < caseFinP){
                load = true;
                if(trame.find("-T") < caseFinP){
                    (trame.find("-",trame.find("-LOAD")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-LOAD")+1) : finChamp = caseFinP;
                    Tbatt = trame.substr(trame.find("-T")+2,finChamp - trame.find("-LOAD"));
                }
            }

            if(trame.find("-T") < caseFinP){
                (trame.find("-",trame.find("-A")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-A")+1) : finChamp = caseFinP;
                Tbatt = trame.substr(trame.find("-T")+2,finChamp - trame.find("-A"));
            }
        }

        if(trame.find("-INST") < caseFinP){
            inst = true;

            if(trame.find("-ON") < caseFinP){
                marche = "ON";
                if(trame.find("-STBY") < caseFinP){
                    modeExp = "STAND-BY";
                    (trame.find("-",trame.find("-ON")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-ON")+1) : finChamp = caseFinP;
                    dureeSTBY = trame.substr(trame.find("-STBY")+5,finChamp - trame.find("-ON"));
                    if(trame.find("-T") < caseFinP){
                        (trame.find("-",trame.find("-STBY")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-STBY")+1) : finChamp = caseFinP;
                        Tinst = trame.substr(trame.find("-T")+2,finChamp - trame.find("-STBY"));
                    }
                }
            }
            if(trame.find("-OFF") < caseFinP){
                marche = "OFF";
                if(trame.find("-STBY") < caseFinP){
                    modeExp = "STAND-BY";
                    (trame.find("-",trame.find("-OFF")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-OFF")+1) : finChamp = caseFinP;
                    dureeSTBY = trame.substr(trame.find("-STBY")+5,finChamp - trame.find("-OFF"));
                    if(trame.find("-T") < caseFinP){
                        (trame.find("-",trame.find("-STBY")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-STBY")+1) : finChamp = caseFinP;
                        Tinst = trame.substr(trame.find("-T")+2,finChamp - trame.find("-STBY"));
                    }
                }
            }

            if(trame.find("-E") < caseFinP){
                erreur = true;
                if(trame.find("-STBY") < caseFinP){
                    modeExp = "STAND-BY";
                    (trame.find("-",trame.find("-E")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-E")+1) : finChamp = caseFinP;
                    dureeSTBY = trame.substr(trame.find("-STBY")+5,finChamp - trame.find("-E"));
                    if(trame.find("-T") < caseFinP){
                        (trame.find("-",trame.find("-STBY")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-STBY")+1) : finChamp = caseFinP;
                        Tinst = trame.substr(trame.find("-T")+2,finChamp - trame.find("-STBY"));
                    }
                }
            }

            if(trame.find("-NORM") < caseFinP){
                modeExp = "NORMAL";
                if(trame.find("-T") < caseFinP){
                    (trame.find("-",trame.find("-NORM")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-NORM")+1) : finChamp = caseFinP;
                    Tinst = trame.substr(trame.find("-T")+2,finChamp - trame.find("-NORM"));
                }
            }
            if(trame.find("-SLEEP") < caseFinP){
                modeExp = "SLEEP";
                if(trame.find("-T") < caseFinP){
                    (trame.find("-",trame.find("-SLEEP")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-SLEEP")+1) : finChamp = caseFinP;
                    Tinst = trame.substr(trame.find("-T")+2,finChamp - trame.find("-SLEEP"));
                }
            }

            
            
        }

        if(trame.find("-CUBE") < caseFinP){
            cube = true;

            if(trame.find("-T") < caseFinP){
                (trame.find("-",trame.find("-CUBE")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-CUBE")+1) : finChamp = caseFinP;
                Tcube = trame.substr(trame.find("-T")+2,finChamp - trame.find("-CUBE"));
            }
        }

        if(trame.find("-REBOOT") < caseFinP){
            reboot = true;
            
            if(trame.find("-DT") < caseFinP){
                (trame.find("-",trame.find("-REBOOT")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-REBOOT")+1) : finChamp = caseFinP;
                DTr = trame.substr(trame.find("-DT")+3,finChamp - trame.find("-REBOOT"));
            }

            if(trame.find("-N") < caseFinP){
                (trame.find("-",trame.find("-DT")+1) < caseFinP ) ? finChamp = trame.find("-",trame.find("-DT")+1) : finChamp = caseFinP;
                N = trame.substr(trame.find("-N")+2,finChamp - trame.find("-DT"));
            }
        }

        if(trame[NUM_TRAME] == trame[NBRE_TRAMES]){
            compteur = 1;//reset du compteur
        }
    }else{
        cout<<"trame precedente non complete"<<endl;
        security = true;
        if(trame[NUM_TRAME]==1){
            cout<<"debut nouvelle trame abandon de la precedente"<<endl;
            compteur = 1;
            extraireDonnee(trame);
        }
    }
}

string Status::genereTrame(){
    json trame;
    if(compteur == 1 && security == false){
        if(bord){
            trame["status"]["bord"]["Stockage SD libre"] = SMo + "Mo";
            trame["status"]["bord"]["Occupation RAM en %"] = Rp + "%";
            trame["status"]["bord"]["Temperature processeur"] = Tbord + "°C";
            trame["status"]["bord"]["Date/heure à bord"] = DTb;
        }
        
        if(batt){
            trame["status"]["batt"]["Niveau charge"] = C + "%";
            trame["status"]["batt"]["Tension batterie"] = V + "V";
            trame["status"]["batt"]["Courant"] = A + "mA";
            trame["status"]["batt"]["Temperature batterie"] = Tbatt + "°C";
            if(load){
                trame["status"]["batt"]["Charge"] = "OUI";
            }
            else{
                trame["status"]["batt"]["Charge"] = "NON";
            }
        }

        if(inst){
            trame["status"]["inst"]["Marche"] = marche;
            trame["status"]["inst"]["Mode"] = modeExp;
            if(modeExp == "STBY"){
                trame["status"]["inst"]["Duree mode"] = dureeSTBY;
            }

            trame["status"]["inst"]["Temperature instrument"] = Tinst + "°C";
            if(erreur){
                trame["status"]["inst"]["erreur"] = "OUI";
            }
            else{
                trame["status"]["inst"]["erreur"] = "NON";
            }
        }

        if(cube){
            trame["status"]["cube"]["Temperature cube"] = Tcube + "°C";
        }

        if(reboot){
            trame["status"]["reboot"]["Date dernier reboot"] = DTr;
            trame["status"]["reboot"]["Nombre reboot"] = N;
        }

        return trame.dump();
    }else{
        cout<<"trame precedente pas fini"<<endl;
        return "";
    }
}

Status::~Status() {

}