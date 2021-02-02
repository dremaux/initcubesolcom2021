#include "CubeEventServer.h"

int main()
{
	CubeEventServer* cgi = new CubeEventServer("127.0.0.1","9950");
	cgi -> transmettreEntete();
	while (1)
		cgi->traiterEvenement();
	return 0;
}
