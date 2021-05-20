/// Les Inclusions
#include <iostream>
#include "Serial.h"


using namespace std;


int main()
{
    Serial* maLiaisonSerie;
    maLiaisonSerie = new Serial("dev/ttyS0",9600);
    string message = "Bonjour!"; //La variable qui va nous servir pour le message
    maLiaisonSerie->writeString(message); //On stocke le message pour l'envoyer dans "message"
    cout << "Message envoyé : " << message << endl;
}


/*
///Code principal("main")
int main()
{
    ///Initialisation des variables
    int a =1; //La constante "a" va nous permettre de faire une boucle infinie
    string message; //La variable qui va nous servir pour le message
    Serial maLiaisonSerie("/dev/ttyS0",9600); //Parametrer le débit et le port d'arrivé du message

    while ( a==1 ) //La boucle infinie vu que "a" est une constante
    {
        message = maLiaisonSerie.readLine(); //On stocke le message reçu de la liaison série dans "message"
        cout << "Message reçu : " << message << endl; // affiche le message reçu
    }
    return 0;
}
*/


/*
int serveurEcoute()
{
    char tableau[100];

    while (true) {

        serialib * monObjSerial = new serialib; //Déclaration de l'instance

        monObjSerial->Open("/dev/serial0", 9600); //Ouverture

        char varID = leSegment->getIdentifiant();

        int typeRetourTrame = monObjSerial->ReadString(tableau, '\n', 128, 3000);
        cout << "Valeur de Retour : " << typeRetourTrame << endl;

        if (typeRetourTrame == 0) {
            cout << "Pas de commande reçu." << endl;
            monObjSerial->Close();

        } else if (typeRetourTrame == -1) {
            cout << "Erreur TimeOut mal définie" << endl;
            monObjSerial->Close();

        } else if (typeRetourTrame == -2) {
            cout << "Erreur impossible d'accéder à la ressource." << endl;
            monObjSerial->Close();

        } else if (typeRetourTrame == -3) {
            cout << "Erreur, trop d'octects lus." << endl;
            this->envoieACK("BUSY");
            monObjSerial->Close();

        } else if (typeRetourTrame > 1) {
            cout << "Reception de la Commande OK " << endl;

            cout << "Trame Lue : ";
            for (int i(0); i < typeRetourTrame; i++) {
                cout << tableau[i];
            }
            if (tableau[1] == varID) {
                cout << "La commande est pour notre Cube" << endl;

                bool boolChecksum = this->verifierChecksum();
                if (boolChecksum == true) {
                    this->envoieACK("ACK");
                    this->traiterCommande(); //Mettre à Traiter la commande
                }
                if (boolChecksum == false) {
                    this->envoieACK("NACK");
                }

            } else {
                cout << "La commande n'est pas pour notre Cube" << endl;
            }
            monObjSerial->Close();

        } else {
            monObjSerial->Close();

        }
    }
*/
