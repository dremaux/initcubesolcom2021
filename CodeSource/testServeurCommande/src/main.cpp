#include "CubeEventServer.h"

int main()
{
	CubeEventServer* cgi = new CubeEventServer("127.0.0.1","9951");
	cgi -> transmettreEntete();
	
	cgi->transmettreJSON(ETAT,"test");
	delete cgi;
	return 0;
}
