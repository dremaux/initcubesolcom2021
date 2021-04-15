#include "Lib.h"
#include <thread>
#include "Measure.hpp"


using namespace std;
void testImage();
void testMatrice();
void testSimple();

int main()
{
    testSimple();
	return 0;
}

void testSimple(){
    string trame;
	Measure* m = new Measure();
    unsigned char trameI[34];
    trameI[0] = '~' ;
    trameI[1] = 1;
    trameI[2] = 27;
    trameI[3] = 'M';
    trameI[4] = 'E';
    trameI[5] = 'A';
    trameI[6] = 'S';
    trameI[7] = 'U';
    trameI[8] = 'R';
    trameI[9] = 'E';
    trameI[NBRE_TRAMES] = 1;
    trameI[NUM_TRAME] = 1;
    trameI[12] = '-';
    trameI[13] = 'T';
    trameI[14] = 'C';
    trameI[30] = ' ';
    trameI[31] = 'C';
    trameI[32] = '7';
    trameI[33] = 255;
    

    string s;

    for(int y = 15; y <= 29; y = y +5){
        trameI[y] = ' ';
        trameI[y+1] = (rand()%10)+48;
        trameI[y+2] = (rand()%10)+48;
        trameI[y+3] = '.';
        trameI[y+4] = (rand()%10)+48;
    }
    trame = reinterpret_cast<char*>(trameI);
    m->setTrame(trame);
    m->identifierType();
    s = m->genererTrame();

    cout<<s<<endl;
}

void testMatrice(){
    string trame;
	Measure* m = new Measure();
    unsigned char trameI[60];
    trameI[0] = '~' ;
    trameI[1] = 1;
    trameI[2] = 53;
    trameI[3] = 'M';
    trameI[4] = 'E';
    trameI[5] = 'A';
    trameI[6] = 'S';
    trameI[7] = 'U';
    trameI[8] = 'R';
    trameI[9] = 'E';
    trameI[NBRE_TRAMES] = 8;
    trameI[NUM_TRAME] = 1;
    trameI[12] = '-';
    trameI[13] = 'P';
    trameI[14] = 'I';
    trameI[15] = 'X';
    trameI[56] = ' ';
    trameI[57] = 'C';
    trameI[58] = '7';
    trameI[59] = 255;
    

    string s;
    for(int i= 1;i<=8;i++){
        for(int y = 16; y <= 55; y = y +5){
            trameI[y] = ' ';
            trameI[y+1] = (rand()%10)+48;
            trameI[y+2] = (rand()%10)+48;
            trameI[y+3] = '.';
            trameI[y+4] = (rand()%10)+48;
        }
        trameI[NUM_TRAME] = i;
        trame = reinterpret_cast<char*>(trameI);
        m->setTrame(trame);
        m->identifierType();
        s = m->genererTrame();
    }
    cout<<s<<endl;
}

void testImage(){
    string trame;
	Measure* m = new Measure();
    unsigned char trameI[70];
    trameI[0] = '~' ;
    trameI[1] = 1;
    trameI[2] = 63;
    trameI[3] = 'M';
    trameI[4] = 'E';
    trameI[5] = 'A';
    trameI[6] = 'S';
    trameI[7] = 'U';
    trameI[8] = 'R';
    trameI[9] = 'E';
    trameI[NBRE_LIGNES] = 240;
    trameI[NUM_LIGNE] = 1;
    trameI[NBRE_SECTION] = 20;
    trameI[NUM_SECTION] = 1;
    trameI[14] = '-';
    trameI[15] = 'I';
    trameI[16] = 'M';
    trameI[17] = 'G';
    trameI[18] = ' ';
    trameI[67] = 'C';
    trameI[68] = '7';
    trameI[69] = 255;
    

    string s;
    int t = 0;
    for(int y = 1; y <= 240; y++){
        for(int x = 1; x <= 20; x++){
            for(int i = 19; i < 67; i++){
                trameI[i] = rand()%240 + 1;
            }
            trameI[NUM_LIGNE] = y;
            trameI[NUM_SECTION] = x;
            trame = reinterpret_cast<char*>(trameI);
            m->setTrame(trame);
            m->identifierType();
            s = m->genererTrame();

        }
    }
    cout<<s<<endl;
}