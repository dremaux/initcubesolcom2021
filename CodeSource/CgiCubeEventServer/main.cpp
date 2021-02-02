#include "CubeEventServer.h"

int main()
{
	CubeEventServer* cgi = new CubeEventServer("localhost","9950");
	cgi -> transmettreEntete();
	while (1)
		cgi->traiterEvenement();
	return 0;
}
