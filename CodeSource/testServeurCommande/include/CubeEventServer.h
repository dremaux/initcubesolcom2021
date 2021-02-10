#ifndef CUBEEVENTSERVER_H
#define CUBEEVENTSERVER_H

//#include <iostream>
//#include <unistd.h>
#include "typeMessage.h"
#include "Lib.h"
#include "Communication.h"

class CubeEventServer {
  public:
	CubeEventServer(string adresse,string port);
	~CubeEventServer();
	void transmettreEntete();
	void transmettreEtat(char* message);
	void transmettreJSON(TypeMessage evt,string message);
	void traiterEvenement();
	TypeMessage identifierEvt(string message);
  private:
	Communication* com;
};

#endif

	
