/// Les Inclusions
#include <iostream>
#include "../include/ComInitCube.h"
#include <thread>
#include <unistd.h>

using namespace std;

ComInitCube *comInitCube = new ComInitCube("/dev/ttyUSB0", 9600);

void threadLecture();
void threadEcriture();
void transmettreAck();

int main()
{
    //thread *monThreadEcoute = new thread(threadLecture);
    thread *monThreadEcriture = new thread(threadEcriture);

    //monThreadEcoute->join();
    monThreadEcriture->join();
    return 0;
}
/*
void threadLecture()
{
    int compteur = 0;
    cout<<"lecture"<<endl;
    while(1)
    {
        unsigned char trame[110];//le protocole Xbee nous permet des trames de 104 octets 
        comInitCube->lireTrame(trame, 110);
        cout<<trame<<endl;
        compteur++;
        cout << "nombre de trames recues: " << compteur <<endl;
    }  
}*/

void threadEcriture()
{
    cout << "ecriture" << endl;
    for(int i = 0; i<20; i++)
    {
        unsigned char message[10];
        message[0] = 't';
        message[1] = 'e';
        message[2] = 's';
        message[3] = 't';
        message[4] = 's';
        message[5] = 'o';
        message[6] = 'l';
        message[7] = '\r';
        message[8] = '\n';
        message[9] = 255;
        comInitCube->transmettreTrame(message);
        usleep(100000);
    }
}
