#include "Lib.h"
#include "InitCubeServeur.h"
#include "Commande.hpp"
#include "DispatcheurReponse.hpp"
#include <thread>

void threadConnexionEcoute();
void threadConnexionEcriture();
void threadClient();
void threadEnvoie();
void threadReception();

using namespace std;

int numMap;
bool securite = true;
bool lecture = false;
bool ecriture = false;
InitCubeServeur *serveurEcouteJTP = new InitCubeServeur(9951);	 //json to protocol
InitCubeServeur *serveurEcriturePTJ = new InitCubeServeur(9950); //protocol to json
Commande *commande = new Commande();
Reponse *reponse = new Reponse();

mutex *mtx;
condition_variable cv;

int main()
{
	mtx = serveurEcouteJTP->getMutex();
	thread *monThreadEcoute = new thread(threadConnexionEcoute);
	thread *monThreadEcriture = new thread(threadConnexionEcriture);
	thread *monThreadEnvoie = new thread(threadEnvoie);
	thread *monThreadReception = new thread(threadReception);

	monThreadReception->join();
	monThreadEnvoie->join();
	monThreadEcoute->join();
	monThreadEcriture->join();
	return 0;
}

void threadConnexionEcoute()
{
	while (1)
	{
		numMap = serveurEcouteJTP->attendreConnexion();
		if (numMap >= 0)
		{
			thread *monThreadClient = new thread(threadClient);
		}
	}
}

void threadConnexionEcriture()
{
	while (1)
	{
		serveurEcriturePTJ->attendreConnexion();
	}
}

void threadClient()
{
	int numMapC = numMap;
	int retour = 0;
	while (retour >= 0)
	{
		retour = serveurEcouteJTP->attendreCommande(numMapC);
		if (retour >= 0)
		{
			ecriture = true;
			cv.notify_all();
			ecriture = false;
		}
	}
}

void threadEnvoie()
{
	unique_lock<mutex> lck(*mtx);
	while (1)
	{
		while (!ecriture)
			cv.wait(lck);
		cout << serveurEcouteJTP->getReçu().front() << endl;
		bool set = commande->setTrame(serveurEcouteJTP->getReçu().front());
		serveurEcouteJTP->effacerPremierRecu();
		if (set && commande->extraireDonnees() > 0)
		{
			lecture = false;
			while (securite)
				;
			cout << commande->genererTrame() << endl; //remplacer cout par la liaison serie
			lecture = true;
			cv.notify_all();
		}
	}
}

void threadReception()
{
	string recu;
	unique_lock<mutex> lck(*mtx);
	while (1)
	{
		while (!lecture)
			cv.wait(lck);
		securite = true;
		if (/*liaison serie > */ 0)
		{
			recu = "liaison serie";
			reponse->setTrame(recu);
			string recuR = reponse->identifierType();
			if (recuR == "JSON")
			{
				string trameG = reponse->genererTrame();
				if (recu[10] == recu[11])
				{
					char trameGC[trameG.size() + 1];
					for (int i = 0; i < trameG.size() + 1; i++)
					{
						trameGC[i] = trameG[i];
					}
					serveurEcriturePTJ->transmettre(trameGC, trameG.size());
				}
			}
		}
		securite = false;
	}
}