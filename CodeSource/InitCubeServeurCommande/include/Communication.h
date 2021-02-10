#ifndef COMMUNICATION_H  
#define COMMUNICATION_H
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Communication {
public:
    Communication(string adresse,string port);
    virtual ~Communication();
	int connexion();
	void lancerInitCubeServeur();
    void envoyerMessage(string m);
    int recevoirDonnees();
    char* getBuffer();
private:
    int socket_id;
    string adresse;
    string port;
    char buffer[2000];
};

#endif /* COMMUNICATION_H */
