/// Les Inclusions
#include <iostream>
#include "ComInitCube.h"
#include <thread>
#include <unistd.h>

using namespace std;

ComInitCube *comInitCube = new ComInitCube("/dev/ttyAMA0", 9600);

void threadLecture();
void threadEcriture();
void transmettreAck();

int main()
{
    thread *monThreadEcoute = new thread(threadLecture);
    thread *monThreadEcriture = new thread(threadEcriture);

    monThreadEcoute->join();
    monThreadEcriture->join();
    return 0;
}

void threadLecture()
{
    while(1)
    {
        unsigned char trame[110];//le protocole Xbee nous permet des trames de 104 octets 
        comInitCube->lireTrame(trame, 110);
        cout<<"lecture"<<endl;
        for (int i = 0; i < 110; i++)
        {
            if (trame[i] == 255)
            {
                i = 110;
            }
            else
            {
                cout << trame[i];
                
            }
        }
    }
}

void threadEcriture()
{
    while(1)
    {
        cout << "ecriture" << endl;
        unsigned char message[10];
        message[0] = 't';
        message[1] = 'e';
        message[2] = 's';
        message[3] = 't';
        message[4] = 'o';
        message[5] = 'u';
        message[6] = 'i';
        message[7] = '\r';
        message[8] = '\n';
        message[9] = 255;
        comInitCube->transmettreTrame(message);
        usleep(100000);
    }
}