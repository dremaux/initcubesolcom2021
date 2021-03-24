#include "Lib.h"
#include "InitCubeServeur.h"
#include <thread>
#include "Matrice.hpp"

int main(){
	Matrice* m = new Matrice();
	m->extraireDonnee();
	cout<<m->getDonneeExtraite()<<endl;

}
/*void ThreadConnexion();

using namespace std;



/*Variables globales
 InitCubeServeur* serveur= new InitCubeServeur();

int main()
{
	thread* monThread = new thread(ThreadConnexion);
	
	monThread->join();

	return 0;
}

/*Thread d'attente de connexion
void ThreadConnexion(){
	while(1)//Appel la methode d'écoute du serveur en boucle
		serveur -> attendreConnexion();
}

*/

