/// Les Inclusions
#include <iostream>
#include "ComInitCube.h"
#include <thread>
#include <unistd.h>

using namespace std;

ComInitCube *comInitCube = new ComInitCube("/dev/ttyAMA0", 9600);

void threadLecture();
void threadEcriture();

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
    int y = 0;
    for(int i = 0; i< 2000; i++)
    {
        unsigned char trame[110];//le protocole Xbee nous permet des trames de 104 octets 
        comInitCube->lireTrame(trame, 110);
        cout<<"lecture"<<endl;
        for (int i = 0; i < 110; i++)
        {
            if (trame[i] == 255)
            {
                i = 110;
                y++;
            }
            else
            {
                cout << trame[i];
                
            }
        }
    }
    cout<<y<<endl;
}

void threadEcriture()
{
    for(int i = 0; i< 2000; i++)
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
    }
}