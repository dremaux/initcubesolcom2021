#include "Lib.h"
#include "InitCubeServeur.h"
#include <thread>


void ThreadConnexion();

using namespace std;




InitCubeServeur* serveurEcouteJTP= new InitCubeServeur(9951,false);//json to protocol
InitCubeServeur* serveurEcriturePTJ= new InitCubeServeur(9950,true);//protocol to json

int main()
{
	thread* monThreadEcoute = new thread(ThreadConnexionEcoute);
	thread* monThreadEcriture = new thread(ThreadConnexionEcriture);
	
	monThreadEcoute->join();
	monThreadEcriture->join();

	return 0;
}


void ThreadConnexionEcoute(){
	while(1)//Appel la methode d'écoute du serveur en boucle
		serveurEcouteJTP -> attendreConnexion();
}

void ThreadConnexionEcriture(){
	while(1)//Appel la methode d'écoute du serveur en boucle
		serveurEcriturePTJ -> attendreConnexion();
}