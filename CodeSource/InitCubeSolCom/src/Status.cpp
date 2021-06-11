#include "Status.hpp"

Status::Status()
{
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

void Status::extraireDonnee(std::string trame)
{
    if (trame[NUM_TRAME] == compteur)
    {
        security = false;
        compteur++;
        caseFinP = trame[1] + 2;
        if (trame[NUM_TRAME] == 1)
        {
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

        if (trame.find("-BORD") < caseFinP)
        {
            bord = true;
            if (trame.find("-SMo") < caseFinP)
            {
                (trame.find("-", trame.find("-SMo") + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-SMo") + 1) : finChamp = caseFinP;
                SMo = trame.substr(trame.find("-SMo") + 4, finChamp - (trame.find("-SMo") + 4));
            }

            if (trame.find("-R%") < caseFinP)
            {
                (trame.find("-", trame.find("-R%") + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-R%") + 1) : finChamp = caseFinP;
                Rp = trame.substr(trame.find("-R%") + 3, finChamp - (trame.find("-R%") + 3));
            }

            if (trame.find("-T") < caseFinP)
            {
                (trame.find("-", trame.find("-T", trame.find("-BORD")) + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-T", trame.find("-BORD")) + 1) : finChamp = caseFinP;
                Tbord = trame.substr(trame.find("-T") + 2, finChamp - (trame.find("-T", trame.find("-BORD")) + 2));
            }

            if (trame.find("-DT") < caseFinP)
            {
                (trame.find("-", trame.find("-DT", trame.find("-BORD")) + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-DT", trame.find("-BORD")) + 1) : finChamp = caseFinP;
                DTb = trame.substr(trame.find("-DT") + 3, finChamp - (trame.find("-DT", trame.find("-BORD")) + 3));
            }
        }

        if (trame.find("-BATT") < caseFinP)
        {
            batt = true;
            if (trame.find("-C") < caseFinP)
            {
                (trame.find("-", trame.find("-C") + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-C") + 1) : finChamp = caseFinP;
                C = trame.substr(trame.find("-C") + 2, finChamp - (trame.find("-C") + 2));
            }
            if (trame.find("-V") < caseFinP)
            {
                (trame.find("-", trame.find("-V") + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-V") + 1) : finChamp = caseFinP;
                V = trame.substr(trame.find("-V") + 2, finChamp - (trame.find("-V") + 2));
            }
            if (trame.find("-A") < caseFinP)
            {
                (trame.find("-", trame.find("-A") + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-A") + 1) : finChamp = caseFinP;
                A = trame.substr(trame.find("-A") + 2, finChamp - (trame.find("-A") + 2));
            }
            if (trame.find("-LOAD") < caseFinP)
            {
                load = true;
                if (trame.find("-T") < caseFinP)
                {
                    (trame.find("-", trame.find("-T", trame.find("-BATT")) + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-T", trame.find("-BATT")) + 1) : finChamp = caseFinP;
                    Tbatt = trame.substr(trame.find("-T", trame.find("-BATT")) + 2, finChamp - (trame.find("-T", trame.find("-BATT")) + 2));
                }
            }
            else
            {
                if (trame.find("-T") < caseFinP)
                {
                    (trame.find("-", trame.find("-T", trame.find("-BATT")) + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-T", trame.find("-BATT")) + 1) : finChamp = caseFinP;
                    Tbatt = trame.substr(trame.find("-T", trame.find("-BATT")) + 2, finChamp - (trame.find("-T", trame.find("-BATT")) + 2));
                }
            }
        }

        if (trame.find("-INST") < caseFinP)
        {
            inst = true;

            if (trame.find("-ON") < caseFinP)
            {
                marche = "ON";
                if (trame.find("-STBY") < caseFinP)
                {
                    modeExp = "STAND-BY";
                    (trame.find("-", trame.find("-STBY") + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-STBY") + 1) : finChamp = caseFinP;
                    dureeSTBY = trame.substr(trame.find("-STBY") + 5, finChamp - (trame.find("-STBY") + 5));
                    if (trame.find("-T") < caseFinP)
                    {
                        (trame.find("-", trame.find("-T", trame.find("-INST")) + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-T", trame.find("-INST")) + 1) : finChamp = caseFinP;
                        Tinst = trame.substr(trame.find("-T", trame.find("-INST")) + 2, finChamp - (trame.find("-T", trame.find("-INST")) + 2));
                    }
                }
            }
            if (trame.find("-OFF") < caseFinP)
            {
                marche = "OFF";
                if (trame.find("-STBY") < caseFinP)
                {
                    modeExp = "STAND-BY";
                    (trame.find("-", trame.find("-STBY") + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-STBY") + 1) : finChamp = caseFinP;
                    dureeSTBY = trame.substr(trame.find("-STBY") + 5, finChamp - (trame.find("-STBY") + 5));
                    if (trame.find("-T") < caseFinP)
                    {
                        (trame.find("-", trame.find("-T", trame.find("-INST")) + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-T", trame.find("-INST")) + 1) : finChamp = caseFinP;
                        Tinst = trame.substr(trame.find("-T", trame.find("-INST")) + 2, finChamp - (trame.find("-T", trame.find("-INST")) + 2));
                    }
                }
            }

            if (trame.find("-E") < caseFinP)
            {
                erreur = true;
                if (trame.find("-STBY") < caseFinP)
                {
                    modeExp = "STAND-BY";
                    (trame.find("-", trame.find("-STBY") + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-STBY") + 1) : finChamp = caseFinP;
                    dureeSTBY = trame.substr(trame.find("-STBY") + 5, finChamp - (trame.find("-STBY") + 5));
                    if (trame.find("-T") < caseFinP)
                    {
                        (trame.find("-", trame.find("-T", trame.find("-INST")) + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-T", trame.find("-INST")) + 1) : finChamp = caseFinP;
                        Tinst = trame.substr(trame.find("-T", trame.find("-INST")) + 2, finChamp - (trame.find("-T", trame.find("-INST")) + 2));
                    }
                }
            }

            if (trame.find("-NORM") < caseFinP)
            {
                modeExp = "NORMAL";
                if (trame.find("-T") < caseFinP)
                {
                    (trame.find("-", trame.find("-T", trame.find("-INST")) + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-T", trame.find("-INST")) + 1) : finChamp = caseFinP;
                    Tinst = trame.substr(trame.find("-T", trame.find("-INST")) + 2, finChamp - (trame.find("-T", trame.find("-INST")) + 2));
                }
            }
            if (trame.find("-SLEEP") < caseFinP)
            {
                modeExp = "SLEEP";
                if (trame.find("-T") < caseFinP)
                {
                    (trame.find("-", trame.find("-T", trame.find("-INST")) + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-T", trame.find("-INST")) + 1) : finChamp = caseFinP;
                    Tinst = trame.substr(trame.find("-T", trame.find("-INST")) + 2, finChamp - (trame.find("-T", trame.find("-INST")) + 2));
                }
            }
        }

        if (trame.find("-CUBE") < caseFinP)
        {
            cube = true;

            if (trame.find("-T") < caseFinP)
            {
                (trame.find("-", trame.find("-T", trame.find("-CUBE")) + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-T", trame.find("-CUBE")) + 1) : finChamp = caseFinP;
                Tcube = trame.substr(trame.find("-T", trame.find("-CUBE")) + 2, finChamp - (trame.find("-T", trame.find("-CUBE")) + 2));
            }
        }

        if (trame.find("-REBOOT") < caseFinP)
        {
            reboot = true;

            if (trame.find("-DT") < caseFinP)
            {
                (trame.find("-", trame.find("-DT", trame.find("-REBOOT")) + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-DT", trame.find("-REBOOT")) + 1) : finChamp = caseFinP;
                DTr = trame.substr(trame.find("-DT", trame.find("-REBOOT")) + 3, finChamp - (trame.find("-DT", trame.find("-REBOOT")) + 3));
            }

            if (trame.find("-N") < caseFinP)
            {
                (trame.find("-", trame.find("-N") + 1) < caseFinP) ? finChamp = trame.find("-", trame.find("-N") + 1) : finChamp = caseFinP;
                N = trame.substr(trame.find("-N") + 2, finChamp - (trame.find("-N") + 2));
            }
        }

        if (trame[NUM_TRAME] == trame[NBRE_TRAMES])
        {
            compteur = 1; //reset du compteur
        }
    }
    else
    {
        cout << "trame precedente non complete" << endl;
        security = true;
        if (trame[NUM_TRAME] == 1)
        {
            cout << "debut nouvelle trame abandon de la precedente" << endl;
            compteur = 1;
            extraireDonnee(trame);
        }
    }
}

std::string Status::genereTrame()
{
    json trame;
    if (compteur == 1 && security == false)
    {
        if (bord)
        {
            trame["status"]["bord"]["StockageSDLibreMo"] = SMo;
            trame["status"]["bord"]["OccupationRAM"] = Rp;
            trame["status"]["bord"]["Temperature"] = Tbord;
            trame["status"]["bord"]["Date-heureBord"] = DTb;
        }

        if (batt)
        {
            trame["status"]["batterie"]["NiveauCharge"] = C;
            trame["status"]["batterie"]["TensionV"] = V;
            trame["status"]["batterie"]["CourantmA"] = A;
            trame["status"]["batterie"]["Temperature"] = Tbatt;
            if (load)
            {
                trame["status"]["batterie"]["Charge"] = "OUI";
            }
            else
            {
                trame["status"]["batterie"]["Charge"] = "NON";
            }
        }

        if (inst)
        {
            trame["status"]["instrument"]["Marche"] = marche;
            trame["status"]["instrument"]["Mode"] = modeExp;
            if (modeExp == "STBY")
            {
                trame["status"]["instrument"]["DureeMode"] = dureeSTBY;
            }

            trame["status"]["instrument"]["Temperature"] = Tinst;
            if (erreur)
            {
                trame["status"]["instrument"]["erreur"] = "OUI";
            }
            else
            {
                trame["status"]["instrument"]["erreur"] = "NON";
            }
        }

        if (cube)
        {
            trame["status"]["cube"]["Temperature"] = Tcube;
        }

        if (reboot)
        {
            trame["status"]["reboot"]["DateDernierReboot"] = DTr;
            trame["status"]["reboot"]["NombreReboot"] = N;
        }

        return trame.dump();
    }

    return "";
}

Status::~Status()
{
}