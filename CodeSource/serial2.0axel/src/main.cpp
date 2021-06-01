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
    while (1)
    {
        char *trame = comInitCube->lireTrame2();
        cout<<trame<<endl;
    }
}

void threadEcriture(){
    while(1){
        char message[4];
        message[0] = 't';
        message[1] = '\r';
        message[2] = '\n';
        message[3] = 255;
        comInitCube->transmettreTrame(message);
        sleep(2);
    }
}