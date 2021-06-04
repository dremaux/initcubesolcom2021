#include "Lib.h"
#include "InitCubeServeur.h"


void* ThreadConnexion(void *);
void* ThreadEnvoyerTrame(void *);

using namespace std;

/*Variables globales*/
 InitCubeServeur* serveur= new InitCubeServeur();

int main()
{
	cout<<serveur->genFakeStateFrame()<<endl<<endl;

	cout<<serveur->genFakeInstrumentFrame()<<endl<<endl;

	
	return 0;
}

/*Thread d'attente de connexion*/



/*Thread de mise en forme des trames*/
void* ThreadEnvoyerTrame(void *){
	while(1) {
		//génération de la fausse trame d'état		
		std::string fakeTrameEtat = serveur->genFakeStateFrame()+"\r\n";
		//Envoi de la fausse trame
		serveur->transmettre((char*)fakeTrameEtat.c_str(), fakeTrameEtat.length());
		//temporisation
		usleep (1000000);  
		//génération de la fausse trame de mesure instrument		
		std::string fakeTrameInstrument = serveur->genFakeInstrumentFrame()+"\r\n";
		//Envoi de la fausse trame
		serveur->transmettre((char*)fakeTrameInstrument.c_str(), fakeTrameInstrument.length());
		//temporisation
		usleep (1000000);  
	}
}
