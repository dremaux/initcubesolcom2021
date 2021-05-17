#include "Lib.h"
#include <thread>
#include "Reponse.hpp"

using namespace std;
Reponse *reponse = new Reponse();
void testStatus();
void testSimpleMe();
void testMatriceMe();
void testImageMe();
void testSimpleMi();
void testMatriceMi();
void testImageMi();

int main()
{
    testStatus();
    testSimpleMe();
    testMatriceMe();
    testImageMe();
    testSimpleMi();
    testMatriceMi();
    testImageMi();
    return 0;
}

void testStatus()
{
    char trame1[93];
    trame1[0] = '~';
    trame1[1] = 1;
    trame1[2] = 87;
    trame1[3] = 'S';
    trame1[4] = 'T';
    trame1[5] = 'A';
    trame1[6] = 'T';
    trame1[7] = 'U';
    trame1[8] = 'S';
    trame1[9] = 2;
    trame1[10] = 1;
    trame1[11] = '-';
    trame1[12] = 'B';
    trame1[13] = 'O';
    trame1[14] = 'R';
    trame1[15] = 'D';
    trame1[16] = '-';
    trame1[17] = 'S';
    trame1[18] = 'M';
    trame1[19] = 'o';
    trame1[20] = '6';
    trame1[21] = '1';
    trame1[22] = '5';
    trame1[23] = '2';
    trame1[24] = '0';
    trame1[25] = '6';
    trame1[26] = '8';
    trame1[27] = '-';
    trame1[28] = 'R';
    trame1[29] = '%';
    trame1[30] = '4';
    trame1[31] = '-';
    trame1[32] = 'T';
    trame1[33] = '5';
    trame1[34] = '1';
    trame1[35] = '.';
    trame1[36] = '5';
    trame1[37] = '-';
    trame1[38] = 'D';
    trame1[39] = 'T';
    trame1[40] = '2';
    trame1[41] = '0';
    trame1[42] = '2';
    trame1[43] = '1';
    trame1[44] = '/';
    trame1[45] = '0';
    trame1[46] = '3';
    trame1[47] = '/';
    trame1[48] = '3';
    trame1[49] = '1';
    trame1[50] = ' ';
    trame1[51] = '1';
    trame1[52] = '5';
    trame1[53] = ':';
    trame1[54] = '0';
    trame1[55] = '0';
    trame1[56] = ':';
    trame1[57] = '0';
    trame1[58] = '7';
    trame1[59] = '-';
    trame1[60] = 'B';
    trame1[61] = 'A';
    trame1[62] = 'T';
    trame1[63] = 'T';
    trame1[64] = '-';
    trame1[65] = 'C';
    trame1[66] = '9';
    trame1[67] = '6';
    trame1[68] = '-';
    trame1[69] = 'V';
    trame1[70] = '4';
    trame1[71] = '.';
    trame1[72] = '1';
    trame1[73] = '-';
    trame1[74] = 'A';
    trame1[75] = '1';
    trame1[76] = '2';
    trame1[77] = '9';
    trame1[78] = '5';
    trame1[79] = '-';
    trame1[80] = 'L';
    trame1[81] = 'O';
    trame1[82] = 'A';
    trame1[83] = 'D';
    trame1[84] = '-';
    trame1[85] = 'T';
    trame1[86] = '3';
    trame1[87] = '8';
    trame1[88] = '.';
    trame1[89] = '0';
    trame1[90] = '3';
    trame1[91] = '4';
    trame1[92] = 255;

    char trame2[45];

    trame2[0] = '~';
    trame2[1] = 1;
    trame2[2] = 39;
    trame2[3] = 'S';
    trame2[4] = 'T';
    trame2[5] = 'A';
    trame2[6] = 'T';
    trame2[7] = 'U';
    trame2[8] = 'S';
    trame2[9] = 2;
    trame2[10] = 2;
    trame2[11] = '-';
    trame2[12] = 'I';
    trame2[13] = 'N';
    trame2[14] = 'S';
    trame2[15] = 'T';
    trame2[16] = '-';
    trame2[17] = 'O';
    trame2[18] = 'N';
    trame2[19] = '-';
    trame2[20] = 'N';
    trame2[21] = 'O';
    trame2[22] = 'R';
    trame2[23] = 'M';
    trame2[24] = '-';
    trame2[25] = 'T';
    trame2[26] = '2';
    trame2[27] = '8';
    trame2[28] = '.';
    trame2[29] = '8';
    trame2[30] = '-';
    trame2[31] = 'C';
    trame2[32] = 'U';
    trame2[33] = 'B';
    trame2[34] = 'E';
    trame2[35] = '-';
    trame2[36] = 'T';
    trame2[37] = '1';
    trame2[38] = '9';
    trame2[39] = '7';
    trame2[40] = '.';
    trame2[41] = '4';
    trame2[42] = '0';
    trame2[43] = '9';
    trame2[44] = 255;
    trame2[45] = 0;

    string trameP;
    string trameD;
    string s;
    trameP = trame1;
    reponse->setTrame(trameP);
    reponse->identifierType();
    trameD = trame2;
    reponse->setTrame(trameD);
    reponse->identifierType();
    s = reponse->genererTrame();

    cout << s << endl;
}

void testSimpleMe()
{
    string trame;
    char trameI[34];
    trameI[0] = '~';
    trameI[1] = 1;
    trameI[2] = 28;
    trameI[3] = 'M';
    trameI[4] = 'E';
    trameI[5] = 'A';
    trameI[6] = 'S';
    trameI[7] = 'U';
    trameI[8] = 'R';
    trameI[9] = 'E';
    trameI[10] = 1;
    trameI[11] = 1;
    trameI[12] = '-';
    trameI[13] = 'T';
    trameI[14] = 'C';
    trameI[30] = ' ';
    trameI[31] = 'C';
    trameI[32] = '7';
    trameI[33] = 255;

    string s;

    for (int y = 15; y <= 29; y = y + 5)
    {
        trameI[y] = ' ';
        trameI[y + 1] = (rand() % 10) + 48;
        trameI[y + 2] = (rand() % 10) + 48;
        trameI[y + 3] = '.';
        trameI[y + 4] = (rand() % 10) + 48;
    }
    trame = trameI;
    reponse->setTrame(trame);
    reponse->identifierType();
    s = reponse->genererTrame();

    cout << s << endl;
}

void testMatriceMe()
{
    string trame;
    char trameI[60];
    trameI[0] = '~';
    trameI[1] = 1;
    trameI[2] = 54;
    trameI[3] = 'M';
    trameI[4] = 'E';
    trameI[5] = 'A';
    trameI[6] = 'S';
    trameI[7] = 'U';
    trameI[8] = 'R';
    trameI[9] = 'E';
    trameI[10] = 8;
    trameI[11] = 1;
    trameI[12] = '-';
    trameI[13] = 'P';
    trameI[14] = 'I';
    trameI[15] = 'X';
    trameI[56] = ' ';
    trameI[57] = 'C';
    trameI[58] = '7';
    trameI[59] = 255;

    string s;
    for (int i = 1; i <= 8; i++)
    {
        for (int y = 16; y <= 55; y = y + 5)
        {
            trameI[y] = ' ';
            trameI[y + 1] = (rand() % 10) + 48;
            trameI[y + 2] = (rand() % 10) + 48;
            trameI[y + 3] = '.';
            trameI[y + 4] = (rand() % 10) + 48;
        }
        trameI[11] = i;
        trame = trameI;
        reponse->setTrame(trame);
        reponse->identifierType();
        s = reponse->genererTrame();
    }
    cout << s << endl;
}

void testImageMe()
{
    string trame;
    unsigned char trameI[70];
    trameI[0] = '~';
    trameI[1] = 1;
    trameI[2] = 64;
    trameI[3] = 'M';
    trameI[4] = 'E';
    trameI[5] = 'A';
    trameI[6] = 'S';
    trameI[7] = 'U';
    trameI[8] = 'R';
    trameI[9] = 'E';
    trameI[10] = 240;
    trameI[11] = 1;
    trameI[12] = 20;
    trameI[13] = 1;
    trameI[14] = '-';
    trameI[15] = 'I';
    trameI[16] = 'M';
    trameI[17] = 'G';
    trameI[18] = ' ';
    trameI[67] = 'C';
    trameI[68] = '7';
    trameI[69] = 255;

    string s;
    for (int y = 1; y <= 240; y++)
    {
        for (int x = 1; x <= 20; x++)
        {
            for (int i = 19; i < 67; i++)
            {
                trameI[i] = rand() % 240 + 1;
            }
            trameI[11] = y;
            trameI[13] = x;
            trame = reinterpret_cast<char *>(trameI);
            reponse->setTrame(trame);
            reponse->identifierType();
            s = reponse->genererTrame();
        }
    }
    cout << s << endl;
}

void testSimpleMi()
{
    string trame;
    char trameI[78];
    trameI[0] = '~';
    trameI[1] = 1;
    trameI[2] = 72;
    trameI[3] = 'M';
    trameI[4] = 'I';
    trameI[5] = 'S';
    trameI[6] = 'S';
    trameI[7] = 'I';
    trameI[8] = 'O';
    trameI[9] = 'N';
    trameI[10] = 1;
    trameI[11] = 1;
    trameI[12] = '-';
    trameI[13] = 'T';
    trameI[14] = 'C';
    trameI[75] = 'C';
    trameI[76] = '7';
    trameI[77] = 255;

    string s;

    for (int y = 15; y < 75; y = y + 30)
    {
        trameI[y] = ' ';
        trameI[y + 1] = '-';
        trameI[y + 2] = 'T';
        trameI[y + 3] = (rand() % 10) + 48;
        trameI[y + 4] = (rand() % 10) + 48;
        trameI[y + 5] = '.';
        trameI[y + 6] = (rand() % 10) + 48;
        trameI[y + 7] = ' ';
        trameI[y + 8] = '-';
        trameI[y + 9] = 'D';
        trameI[y + 10] = 'T';
        trameI[y + 11] = '2';
        trameI[y + 12] = '0';
        trameI[y + 13] = '2';
        trameI[y + 14] = '1';
        trameI[y + 15] = '/';
        trameI[y + 16] = '0';
        trameI[y + 17] = '3';
        trameI[y + 18] = '/';
        trameI[y + 19] = '3';
        trameI[y + 20] = '1';
        trameI[y + 21] = ' ';
        trameI[y + 22] = '1';
        trameI[y + 23] = '5';
        trameI[y + 24] = ':';
        trameI[y + 25] = '0';
        trameI[y + 26] = '0';
        trameI[y + 27] = ':';
        trameI[y + 28] = '0';
        trameI[y + 29] = '7';
    }
    trame = trameI;
    reponse->setTrame(trame);
    reponse->identifierType();
    s = reponse->genererTrame();

    cout << s << endl;
}

void testMatriceMi()
{
    string trame;
    char trameI[60];
    trameI[0] = '~';
    trameI[1] = 1;
    trameI[2] = 54;
    trameI[3] = 'M';
    trameI[4] = 'I';
    trameI[5] = 'S';
    trameI[6] = 'S';
    trameI[7] = 'I';
    trameI[8] = 'O';
    trameI[9] = 'N';
    trameI[10] = 8;
    trameI[11] = 1;
    trameI[12] = '-';
    trameI[13] = 'P';
    trameI[14] = 'I';
    trameI[15] = 'X';
    trameI[56] = ' ';
    trameI[57] = 'C';
    trameI[58] = '7';
    trameI[59] = 255;

    string s;
    for (int i = 1; i <= 8; i++)
    {
        for (int y = 16; y <= 55; y = y + 5)
        {
            trameI[y] = ' ';
            trameI[y + 1] = (rand() % 10) + 48;
            trameI[y + 2] = (rand() % 10) + 48;
            trameI[y + 3] = '.';
            trameI[y + 4] = (rand() % 10) + 48;
        }
        trameI[11] = i;
        trame = trameI;
        if (trameI[11] == trameI[10])
        {
            trame.insert(57, "-DT2021/05/15 11:39:52");
            trame[2] += 22;
        }
        reponse->setTrame(trame);
        reponse->identifierType();
        s = reponse->genererTrame();
    }
    cout << s << endl;
}

void testImageMi()
{
    string trame;
    unsigned char trameI[70];
    trameI[0] = '~';
    trameI[1] = 1;
    trameI[2] = 64;
    trameI[3] = 'M';
    trameI[4] = 'I';
    trameI[5] = 'S';
    trameI[6] = 'S';
    trameI[7] = 'I';
    trameI[8] = 'O';
    trameI[9] = 'N';
    trameI[10] = 240;
    trameI[11] = 1;
    trameI[12] = 20;
    trameI[13] = 1;
    trameI[14] = '-';
    trameI[15] = 'I';
    trameI[16] = 'M';
    trameI[17] = 'G';
    trameI[18] = ' ';
    trameI[67] = 'C';
    trameI[68] = '7';
    trameI[69] = 255;

    string s;
    for (int y = 1; y <= 240; y++)
    {
        for (int x = 1; x <= 20; x++)
        {
            for (int i = 19; i < 67; i++)
            {
                trameI[i] = rand() % 240 + 1;
            }
            trameI[11] = y;
            trameI[13] = x;
            trame = reinterpret_cast<char *>(trameI);
            if (trameI[11] == trameI[10] && trameI[12] == trameI[13])
            {
                trame.insert(67, "-DT2021/05/15 11:39:52");
                trame[2] += 22;
            }
            reponse->setTrame(trame);
            reponse->identifierType();
            s = reponse->genererTrame();
        }
    }
    cout << s << endl;
}