#include "DispatcheurReponse.hpp"

DispatcheurReponse::DispatcheurReponse()
{
    measure = new DispatcheurMeasure();
    status = new Status();
    mission = new DispatcheurMission();
}
void DispatcheurReponse::setTrame(char *trame)
{
    this->trame = trame;
}

string DispatcheurReponse::identifierType()
{
    for (int i = 0; i < 100; i++)
    {
        if (trame[i] == 'M' && trame[i + 1] == 'I' && trame[i + 2] == 'S') //MISSION
        {
            mission->setTrame(trame);
            mission->identifierType();
            return "JSON";
        }
        else if (trame[i] == 'M' && trame[i + 1] == 'E' && trame[i + 2] == 'A') //MEASURE
        {
            measure->setTrame(trame);
            measure->identifierType();
            return "JSON";
        }
        else if (trame[i] == 'S' && trame[i + 1] == 'T' && trame[i + 2] == 'A') //STATUS
        {
            status->extraireDonnee(trame);
            return "JSON";
        }
        else if (trame[i] == 'H' && trame[i + 1] == 'E' && trame[i + 2] == 'L') //HELLO
        {
            return "ACK";
        }
        else if (trame[i] == 'O' && trame[i + 1] == 'K') //OK
        {
            return "ACK";
        }
        else if (trame[i] == 'F' && trame[i + 1] == 'A' && trame[i + 2] == 'I') //FAIL
        {
            return "ACK";
        }
        else if (trame[i] == 'B' && trame[i + 1] == 'U' && trame[i + 2] == 'S') //BUSY
        {
            return "ACK";
        }
        else if (trame[i] == 'N' && trame[i + 1] == 'A' && trame[i + 2] == 'C') //NACK
        {
            return "ACK";
        }
        else if (trame[i] == 'A' && trame[i + 1] == 'C' && trame[i + 2] == 'K') //ACK
        {
            return "ACK";
        }
        else if (trame[i] == 'E' && trame[i + 1] == 'R' && trame[i + 2] == 'R') //ERROR-E
        {
            return "ACK";
        }
    }
    cout << "trame non conforme" << endl;
    return "error";
}

string DispatcheurReponse::genererTrame()
{
    string retour;
    for (int i = 0; i < 100; i++)
    {
        if (trame[i] == 'M' && trame[i + 1] == 'I' && trame[i + 2] == 'S') //MISSION
        {
            retour = mission->genererTrame();
            return retour;
        }
        else if (trame[i] == 'M' && trame[i + 1] == 'E' && trame[i + 2] == 'A') //MEASURE
        {
            retour = measure->genererTrame();
            return retour;
        }
        else if (trame[i] == 'S' && trame[i + 1] == 'T' && trame[i + 2] == 'A') //STATUS
        {
            retour = status->genereTrame();
            return retour;
        }
    }
    cout << "trame mauvaise ou ne nécessite pas de reponse" << endl;
    return "error";
}

DispatcheurReponse::~DispatcheurReponse()
{
    delete measure;
    delete status;
    delete mission;
}