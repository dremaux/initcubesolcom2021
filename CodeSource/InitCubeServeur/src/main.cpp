#include "InitCube.hpp"
#include <thread>

void threadConnexionEcoute();
void threadConnexionEcriture();
void threadEnvoie();
void threadReception();

InitCube* cube = new InitCube();

int main()
{
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
	cube->transmitionCommande();
}

void threadConnexionEcriture()
{
	cube->reseptionTelemesure();
}

void threadEnvoie()
{
	cube->envoieVol();
}

void threadReception()
{
	cube->receptionVol();
}