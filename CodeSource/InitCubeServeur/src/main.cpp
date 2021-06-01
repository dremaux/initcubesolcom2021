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
DispatcheurReponse *reponse = new DispatcheurReponse();

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
<<<<<<< HEAD
	while(1) {
		while(!ecriture) cv.wait(lck);
		cout<<serveurEcouteJTP->getRecu().front()<<endl;
		bool set = commande->setTrame(serveurEcouteJTP->getRecu().front());
=======
	while (1)
	{
		while (!ecriture)
			cv.wait(lck);
<<<<<<< HEAD
		cout << serveurEcouteJTP->getReçu().front() << endl;
		bool set = commande->setTrame(serveurEcouteJTP->getReçu().front());
>>>>>>> 0130ab19c2704cefb2bd63212d12d52256490ad6
=======
		cout << serveurEcouteJTP->getRecu().front() << endl;
		bool set = commande->setTrame(serveurEcouteJTP->getRecu().front());
>>>>>>> 88320fe8d01c7a511f8bf4313f0555ea21f13dcf
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
	unsigned char recu[1];
	unique_lock<mutex> lck(*mtx);
	while (1)
	{
		while (!lecture)
			cv.wait(lck);
		securite = true;
		if (/*liaison serie > */ 0)
		{
			recu[0] = 'l';//liaison serie
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
