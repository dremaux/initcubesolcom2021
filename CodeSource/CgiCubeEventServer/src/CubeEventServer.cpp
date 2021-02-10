#include <iostream>
#include <unistd.h>
#include "CubeEventServer.h"

using namespace std ;

CubeEventServer::CubeEventServer(string adresse,string port){
	com = new Communication(adresse,port);
	com->connexion();
}

CubeEventServer::~CubeEventServer() {
	delete com;
}

void CubeEventServer::transmettreEntete()
{
	cout << "Content-Type: text/event-stream\r\n";
	cout << "Cache-Control: no-cache\r\n";
}

void CubeEventServer::transmettreEtat(char* message)
{
	     /*  	cout << "Event: etat\r\n\r\n";
			//Format JSON*/ 
		cout << "data:" << message <<"\r\n" << endl ;
}

void CubeEventServer::transmettreJSON(TypeMessage evt,string trame){
	switch(evt){
		case ETAT:
			cout << "event: etat"<<"\n";
			cout << "data: "<< trame;
			// com->envoieMessage(trameEtat);
			break;
		case INSTRUMENT:
			cout << "event: instrument"<<"\n";
			cout << "data: "<< trame;
			// com->envoieMessage(trameInstru);
			break;
		default :
			cout << "error: aucune trame";
			// com->envoieMessage('-1');
			break;
	}
}

void CubeEventServer::traiterEvenement()
{
	//Si le serveur répond, on transmet les données reçues    
	if (com->recevoirDonnees() > 0){
		string message(com->getBuffer());
		TypeMessage type = identifierEvt(message);
		if (type != UNKNOWN)
			transmettreJSON(type, message);
	}
    	// this->transmettreEtat(com->getBuffer());
    	
	//sinon, on relance le serveur	
	else 
	{
		com->lancerInitCubeServeur();
		usleep (2000000);	
		com->connexion();
	}
}

TypeMessage CubeEventServer::identifierEvt(string message){
	TypeMessage type;
	if (message.find("etat")!=string::npos)
		type = ETAT;

	else if (message.find("instrument") != string::npos)
		type = INSTRUMENT;
	else
		type = UNKNOWN;
	return type;
}


