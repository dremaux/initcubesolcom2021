#include <iostream>
#include <../include/ComInitCube.h>


using namespace std;
    
    ComInitCube::ComInitCube(std::string port, unsigned int baud_rate)
    {
        cout << "Mise en place du service d'envoi de trame" << endl;
        maLiaisonSerie = new Serial(port,baud_rate);
    }

   void ComInitCube::transmettreTrame(std::string s)
    {
        Serial maLiaisonSerie("/dev/ttyS0",9600); //Parametrer le débit et le port d'arrivé du message
        maLiaisonSerie.writeString(s);
        attendreAck();
    }

    void ComInitCube::lireTrame(std::string message)
    {
        Serial maLiaisonSerie("/dev/ttyS0",9600); //Parametrer le débit et le port d'arrivé du message
        message = maLiaisonSerie.readLine(); //On stocke le message reçu de la liaison série dans "message"
        cout << "Message reçu : " << message << endl; // affiche le message reçu
    }

    bool ComInitCube::attendreAck()
    {
        string result;
        maLiaisonSerie->readLine();
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