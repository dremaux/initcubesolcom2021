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
        //transmettreAck();
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

void transmettreAck(){
    unsigned char ack[8];
    ack[0] = '1';
    ack[1] = '3';
    ack[2] = 'A';
    ack[3] = 'C';
    ack[4] = 'K';
    ack[5] = '7';
    ack[6] = 'C';
    ack[7] = 255;
    comInitCube->transmettreTrame(ack);
}
/*/// Les Inclusions
#include <iostream>
#include "ComInitCube.h"
#include <thread>
#include <unistd.h>

using namespace std;

int main()
{
    unsigned char ack[3];
    ack[0] = 'A';
    ack[1] = 'C';
    ack[2] = 'K';
    ComInitCube *comInitCube = new ComInitCube("/dev/ttyUSB0", 9600);
    while(1){
        unsigned char trame[110];
        comInitCube->lireTrame(trame, 110);
        comInitCube->transmettreTrame(ack);
        for(int i = 0; i<110; i++){
            cout<<trame[i];
        }
        cout<<endl;

    }
    
    

    return 0;
}*/