#include "Lib.h"
#include "InitCubeServeur.h"


void* ThreadConnexion(void *);
void* ThreadReceptionTrame(void *);

using namespace std;

/*Variables globales*/
 InitCubeServeur* serveur= new InitCubeServeur();

int main()
{
	pthread_t threadConnexion;
	pthread_t threadReceptionTrame;
	int err_threadConnexion;
	int err_threadEnvoyerTrame;
	err_threadConnexion = pthread_create(&threadConnexion,NULL,ThreadConnexion,NULL);
	err_threadEnvoyerTrame = pthread_create(&threadReceptionTrame,NULL,ThreadReceptionTrame,NULL);
	pthread_join(threadConnexion, NULL);
   	pthread_join(threadReceptionTrame, NULL);
	return 0;
}

/*Thread d'attente de connexion*/
void* ThreadConnexion(void *){
	while(1)//Appel la methode d'écoute du serveur en boucle
		serveur -> attendreConnexion();
}


/*Thread de mise en forme des trames*/
void* ThreadReceptionTrame(void *){
	while(1) {
		serveur->attendreCommande();
	}
}
