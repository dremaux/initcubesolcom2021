/// Les inclusions
#include <iostream>
#include "../include/ComInitCube.h"


ComInitCube::ComInitCube(std::string port, unsigned int baud_rate)
{
    maLiaisonSerie = new Serial(port, baud_rate);
}


void ComInitCube::transmettreTrame(unsigned char *s)
{
    string retour = "";
    int taille = 0;
    for (int i = 0; i < 110; i++)
    { //le protocole Xbee nous permet des trames de 104 octets
        if (s[i] == 255)
        {
            taille = i + 1;
            i = 110;
        }
    }
    maLiaisonSerie->writeChar(s, taille);
}


bool ComInitCube::lireTrame(unsigned char *trame, int taille)
{
    bool checksum;
    for (int i = 0; i < taille; i++)
    {
        trame[i] = 0;
    }
    unsigned char buf;
    int y = 0;
    while (buf != 255)
    {
        buf = maLiaisonSerie->readChar();
        trame[y] = buf;
        y++;
    }
    
    checksum = verifierChecksum(trame, y);
    if (!checksum)
    {
        return false;
    }
    else
    {
        return true;
    }   
}


string ComInitCube::attendreAck() // attention methode non complete manque cas de non recu
{
    string retour;
    unsigned char trame[110];

    lireTrame(trame, 110);
    retour = reinterpret_cast<char const *>(trame);
    if (retour.find("ACK") < retour.size())
    {
        return "RECU";
    }
    else if (retour.find("NACK") < retour.size())
    {
        return "ERREUR_CKS";
    }
    return "erreur";
}


bool ComInitCube::verifierChecksum(unsigned char* trame, int taille)
{
    unsigned char checkSum1;
    unsigned char checkSum2;
    int h = 0;

    for(int i = 0; i < taille; i++){

        if(trame[i] == 255)
        {
            checkSum1 = trame[i - 2];
            checkSum2 = trame[i - 1];
            h = i;
        }
    }
    calculerChecksum(trame, trame[h-2], trame[h-1], taille-3);
    if (checkSum1 == trame[h-2] && checkSum2 == trame[h-1])
    {
        return true;
    }
    else
    {
        return false;
    }
}


void ComInitCube::calculerChecksum( unsigned char* trame, unsigned char & PF, unsigned char & pf, int taille){
    short Checksum=0;
    char leChecksum[2];
    for (int i=0;i<taille;i++)
    {
        Checksum=Checksum^trame[i];
    }
    sprintf(leChecksum, "%2X",Checksum);
    if (leChecksum[0]==32) leChecksum[0]='0';
    if (leChecksum[1]==32) leChecksum[1]='0';
    PF = leChecksum[0];
    pf = leChecksum[1];

}
