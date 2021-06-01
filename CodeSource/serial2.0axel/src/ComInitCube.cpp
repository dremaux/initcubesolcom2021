#include <iostream>
#include "ComInitCube.h"


ComInitCube::ComInitCube(std::string port, unsigned int baud_rate)
{
    cout << "Mise en place du service d'envoi de trame" << endl;
    maLiaisonSerie = new Serial(port, baud_rate);
}

void ComInitCube::transmettreTrame(unsigned char* s)
{
    //string retour = "";
    int taille = 0;
    for(int i = 0; i< 130;i++){//le protocole Xbee nous permet des trames de 104 octets 
        if(s[i] == 255){
            taille = i + 1;
            i = 130;
        }
    }
    maLiaisonSerie->writeString(s, taille);
    /*retour = attendreAck();
    if(retour == "RECU"){
        cout<<"trame transmise"<<endl;
    }
    else if(retour == "ERREUR_CKS"){
        cout<<"erreur checksum"<<endl;
    }
    else{
        cout<<"ack non reçu"<<endl;
    }*/
}

void ComInitCube::lireTrame(unsigned char* trame, int taille){
    for(int i = 0; i < taille; i++){
        trame[i] = 0;
    }
    unsigned char buf;
    int i = 0;
    while(buf != 255){
        buf = maLiaisonSerie->readChar();
        trame[i] = buf;
        i++;
    }
}

string ComInitCube::attendreAck()
{
    string retour;
    int compteur = 0;
    while (1)
    {
        retour = maLiaisonSerie->readLine();
        compteur++;
        if (retour.find("ACK") < retour.size())
        {
            compteur2 = 0;
            return "RECU";
        }
        else if (retour.find("NACK") < retour.size())
        {
            compteur2++;
            return "ERREUR_CKS";
        }
        else if (compteur == 5)
        {
            compteur2++;
            return "NON_RECU";
        }
        compteur2 ++;
    }
}