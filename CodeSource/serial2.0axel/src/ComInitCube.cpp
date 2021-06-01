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

unsigned char* ComInitCube::lireTrame2(){
    unsigned char trame[110]; // le protocole Xbee nous permet des trames de 104 octets
    for(int i = 0; i < 110; i++){
        trame[i] = 0;
    }
    unsigned char buf;
    int i = 0;
    while(1){
        buf = maLiaisonSerie->readChar();
        if(buf == 255){
            return (unsigned char*)trame;
        }
        trame[i] = buf;
        i++;
    }
}

void ComInitCube::lireTrame(std::string message)
{
    message = maLiaisonSerie->readLine();         //On stocke le message reçu de la liaison série dans "message"
    cout << "Message reçu : " << message << endl; // affiche le message reçu
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