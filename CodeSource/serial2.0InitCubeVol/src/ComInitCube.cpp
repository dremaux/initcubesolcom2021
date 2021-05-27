#include <iostream>
#include <../include/ComInitCube.h>


using namespace std;
    
    ComInitCube::ComInitCube(std::string port, unsigned int baud_rate)
    {
        //cout << "Mise en place du service d'envoi de trame" << endl;
        maLiaisonSerie = new Serial(port,baud_rate);
    }

   void ComInitCube::transmettreTrame(std::string s)
    {
        maLiaisonSerie->writeString(s);
        //attendreAck();
    }

    void ComInitCube::lireTrame(std::string &message)
    {
        message = maLiaisonSerie->readLine(); //On stocke le message reçu de la liaison série dans "message"
        cout << "Message reçu (inside lireTrame) : " << message << endl; // affiche le message reçu
    }

    bool ComInitCube::attendreAck()
    {
        string result;
        result = maLiaisonSerie->readLine();
	//cout << "Message de réception :" << result << endl;
        if (result.find("ACK"))
        {
            cout << "commande reçue par le cube" << endl;
            return true;
        }
        else
        {
            cout << "le cube n'a pas envoyé de réponse ..." << endl;
            return false;
        }
    }
