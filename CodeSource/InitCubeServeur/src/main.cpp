#include "Lib.h"
#include "InitCubeServeur.h"
#include <thread>
#include "Commande.hpp"


int main(){
	Commande* c = new Commande("e");
	c->extraireDonnees();
	c->genererTrame();
	
}

/*void ThreadConnexion();

using namespace std;




 InitCubeServeur* serveur= new InitCubeServeur();

int main()
{
	thread* monThread = new thread(ThreadConnexion);
	
	monThread->join();

	return 0;
}


void ThreadConnexion(){
	while(1)//Appel la methode d'écoute du serveur en boucle
		serveur -> attendreConnexion();
}
*/


