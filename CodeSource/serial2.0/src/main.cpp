/// Les Inclusions
#include <iostream>
#include "../include/Serial.h"

using namespace std;

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
