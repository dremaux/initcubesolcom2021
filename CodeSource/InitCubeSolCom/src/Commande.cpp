#include "Commande.hpp"

using json = nlohmann::json;

Commande::Commande()
{
}

Commande::Commande(string tJson, int numeroCommande) : trame(tJson)
{
    trame = R"({ "CMD": {
            "idSatellite": "1",
            "typeCommande": "MEASURE",
            "refInstrument":"CamInfra",
            "code": "TC"
            "dateEnvoi":"0000/00/00 00:00:00",
            "reponse:"non"
            }
        })"_json;

    nCommande[0] = numeroCommande;
}

Commande::Commande(string tJson) : trame(tJson)
{
}

Commande::~Commande()
{
}

int Commande::extraireDonnees()
{
    if (trame.find("CMD") != trame.end() && trame["CMD"].find("idSatellite") != trame["CMD"].end() && trame["CMD"].find("typeCommande") != trame["CMD"].end())
    {
        id = trame["CMD"]["idSatellite"];
        cmd = trame["CMD"]["typeCommande"];
        if (cmd == "MISSION")
        {
            CMD = MISSION;
            extraireDonneesMis();
            return (1);
        }

        if (cmd == "MEASURE")
        {
            CMD = MEASURE;
            extraireDonneesMea();
            return (1);
        }

        if (cmd == "STATUS")
        {
            CMD = STATUS;
            extraireDonneesSta();
            return (1);
        }

        if (cmd == "DEPLOY")
        {
            CMD = DEPLOY;
            return (1);
        }

        if (cmd == "SURVIVAL")
        {
            CMD = SURVIVAL;
            return (1);
        }

        if (cmd == "EMPTY")
        {
            CMD = EMPTY;
            return (1);
        }

        if (cmd == "SAVE")
        {
            CMD = SAVE;
            return (1);
        }

        if (cmd == "MEETING")
        {
            CMD = MEETING;
            extraireDonneesMee();
            return (1);
        }

        if (cmd == "DATE")
        {
            CMD = DATE;
            return (1);
        }
    }
    else
    {
        cout << "trame non conforme" << endl;
        return (-1);
    }
}

void Commande::extraireDonneesMis()
{
    if (trame["CMD"].find("option") != trame["CMD"].end())
    {
        if (trame["CMD"]["option"].find("periodicite") != trame["CMD"].end())
        {
            periode = trame["CMD"]["option"]["periodicite"];
            periode = "-P" + periode;
        }

        if (trame["CMD"]["option"].find("duree") != trame["CMD"].end())
        {
            duree = trame["CMD"]["option"]["duree"];
            duree = "-D" + duree;
        }

        if (trame["CMD"]["option"].find("deteExec") != trame["CMD"].end())
        {
            date = trame["CMD"]["option"]["dateExec"];
            date = "-DT" + date;
        }

        if (trame["CMD"]["option"].find("save") != trame["CMD"].end())
        {
            save = "-SAVE";
        }
    }
    if (trame["CMD"].find("code") != trame["CMD"].end())
    {
        typeMeasure = trame["CMD"]["code"];
        typeMeasure = "-" + typeMeasure;
    }
}

void Commande::extraireDonneesMea()
{
    if (trame["CMD"].find("code") != trame["CMD"].end())
    {
        typeMeasure = trame["CMD"]["code"];
        typeMeasure = "-" + typeMeasure;
    }
}

void Commande::extraireDonneesSta()
{
    if (trame["CMD"].find("option") != trame["CMD"].end())
    {
        if (trame["CMD"]["option"].find("periodicite") != trame["CMD"].end())
        {
            periode = trame["CMD"]["option"]["periodicite"];
            periode = "-P" + periode;
        }

        if (trame["CMD"]["option"].find("duree") != trame["CMD"].end())
        {
            duree = trame["CMD"]["option"]["duree"];
            duree = "-D" + duree;
        }

        if (trame["CMD"]["option"].find("BORD") != trame["CMD"].end())
        {
            bord = "-BORD";
        }

        if (trame["CMD"]["option"].find("INST") != trame["CMD"].end())
        {
            inst = "-INST";
        }

        if (trame["CMD"]["option"].find("BATT") != trame["CMD"].end())
        {
            batt = "-BATT";
        }

        if (trame["CMD"]["option"].find("REBOOT") != trame["CMD"].end())
        {
            reboot = "-REBOOT";
        }

        if (trame["CMD"]["option"].find("CUBE") != trame["CMD"].end())
        {
            cube = "-CUBE";
        }
    }
}

void Commande::extraireDonneesMee()
{
    if (trame["CMD"].find("option") != trame["CMD"].end())
    {
        if (trame["CMD"]["option"].find("duree") != trame["CMD"].end())
        {
            duree = trame["CMD"]["option"]["duree"];
            duree = "-D" + duree;
        }

        if (trame["CMD"]["option"].find("dateExec") != trame["CMD"].end())
        {
            date = trame["CMD"]["option"]["dateExec"];
            date = "-DT" + date;
        }

        if (trame["CMD"]["option"].find("save") != trame["CMD"].end())
        {
            save = "-SAVE";
        }
    }
}

void Commande::extraireDonneesDat()
{
    if (trame["CMD"].find("option") != trame["CMD"].end())
    {
        if (trame["CMD"]["option"].find("dateExec") != trame["CMD"].end())
        {
            date = trame["CMD"]["option"]["dateExec"];
            date = "-DT" + date;
        }
    }
}

bool Commande::genererTrame(unsigned char *trameF)
{
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
        cout << "problème de trame" << endl;
        return false;
        break;
    }
    nbOctets = trameInter.length();
    trameInter = "  " + trameInter; //les deux espace sont pour l'id et pour le nombre d'octets dans le payload

    strcpy((char *)trameF, trameInter.c_str());
    trameF[0] = stoi(id, nullptr);
    trameF[1] = nbOctets;
    trameF[trameInter.length() + 2] = 255;
    calculerChecksum(trameF, trameF[trameInter.length()], trameF[trameInter.length() + 1]);
    return true;
}

void Commande::calculerChecksum(unsigned char *trameF, unsigned char &PF, unsigned char &pf)
{
    short Checksum = 0;
    char leChecksum[2];

    for (int i = 0; i < nbOctets + 2; i++)
    {
        Checksum = Checksum ^ trameF[i];
    }
    sprintf(leChecksum, "%2X", Checksum);
    if (leChecksum[0] == 32)
        leChecksum[0] = '0';
    if (leChecksum[1] == 32)
        leChecksum[1] = '0';
    PF = leChecksum[0];
    pf = leChecksum[1];
}

bool Commande::setTrame(string trame)
{
    try
    {
        this->trame = json::parse(trame);
        return true;
    }
    catch (json::parse_error &ex)
    {
        cout << "trame reçu non JSON" << endl;
        cout << ex.what() << endl;
        return false;
    }
}
