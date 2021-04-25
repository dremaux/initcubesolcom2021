#include "Lib.h"
#include "InitCubeServeur.h"
#include "Commande.hpp"
#include "Measure.hpp"
#include <thread>


void threadConnexionEcoute();
void threadConnexionEcriture();
void threadClient();
void threadEnvoie();
void threadReception();

using namespace std;


int numMap;
InitCubeServeur* serveurEcouteJTP= new InitCubeServeur(9951);//json to protocol
InitCubeServeur* serveurEcriturePTJ= new InitCubeServeur(9950);//protocol to json
Commande* commande = new Commande();
Measure* measure = new Measure();

int main()
{
	thread* monThreadEcoute = new thread(threadConnexionEcoute);
	thread* monThreadEcriture = new thread(threadConnexionEcriture);
	thread* monThreadEnvoie = new thread(threadEnvoie);
	thread* monThreadReception = new thread(threadReception);

	monThreadReception->join();
	monThreadEnvoie->join();
	monThreadEcoute->join();
	monThreadEcriture->join();
	return 0;
}


void threadConnexionEcoute(){
	while(1){
		numMap = serveurEcouteJTP -> attendreConnexion();
		if(numMap >= 0){			
			thread* monThreadClient = new thread(threadClient);
		}
	}

}

void threadConnexionEcriture(){
	while(1){
		serveurEcriturePTJ -> attendreConnexion();
	}
}

void threadClient(){
	int numMapC = numMap;
	int retour = 0;
	while(retour >= 0){
		retour = serveurEcouteJTP->attendreCommande(numMapC);
		
	}
}

void threadEnvoie(){
	while(1){
		if(serveurEcouteJTP->getReçu().size() != 0){
			commande->setTrame(serveurEcouteJTP->getReçu().front());
			serveurEcouteJTP->getReçu().erase(serveurEcouteJTP->getReçu().begin());
			if(commande->extraireDonnees() > 0){
				cout<<commande->genererTrame()<<endl;//remplacer cout par la liaison serie
			}
		}
	}
}

void threadReception(){
	string recu;
	while(1){
		if("liaison serie" > 0){
			recu = "liaison serie";
			measure->setTrame(recu);
			measure->identifierType();
			string trameG = measure->genererTrame();
			char trameGC[trameG.size()+1];
			serveurEcriturePTJ->transmettre(trameGC,trameG.size());
		}
	}
}