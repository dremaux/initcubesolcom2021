#include "InitCube.hpp"
#include <thread>

void threadConnexionEcoute();
void threadConnexionEcriture();
void threadEnvoieCommande();
void threadReceptionTelemesure();
void threadEnvoieTelemesure();
mongocxx::instance instance{};

InitCube* cube = new InitCube();

int main()
{
	thread *monThreadEcoute = new thread(threadConnexionEcoute);
	thread *monThreadEcriture = new thread(threadConnexionEcriture);
	thread *monThreadEnvoieC = new thread(threadEnvoieCommande);
	thread *monThreadReceptionT = new thread(threadReceptionTelemesure);
	thread *monThreadEnvoieT = new thread(threadEnvoieTelemesure);

	monThreadEnvoieT->join();
	monThreadReceptionT->join();
	monThreadEnvoieC->join();
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
	cube->attenteAbonnement();
}

void threadEnvoieCommande()
{
	cube->envoieVol();
}

void threadReceptionTelemesure()
{
	cube->receptionVol();
}

void threadEnvoieTelemesure(){
	cube->envoieTelemesure();
}