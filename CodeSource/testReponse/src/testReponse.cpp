#include "Lib.h"
#include <thread>
#include "DispatcheurReponse.hpp"

using namespace std;
DispatcheurReponse *reponse = new DispatcheurReponse();
void testStatus();
void testSimpleMe();
void testMatriceMe();
void testImageMe();
void testSimpleMi();
void testMatriceMi();
void testImageMi();

int main()
{
    //testStatus();
    //testSimpleMe();
    //testMatriceMe();
    //testImageMe();
    //testSimpleMi();
    //testMatriceMi();
    //testImageMi();
    return 0;
}

void testStatus()
{
    unsigned char trame1[92];
    trame1[0] = 1;
    trame1[1] = 87;
    trame1[2] = 'S';
    trame1[3] = 'T';
    trame1[4] = 'A';
    trame1[5] = 'T';
    trame1[6] = 'U';
    trame1[7] = 'S';
    trame1[8] = 2;
    trame1[9] = 1;
    trame1[10] = '-';
    trame1[11] = 'B';
    trame1[12] = 'O';
    trame1[13] = 'R';
    trame1[14] = 'D';
    trame1[15] = '-';
    trame1[16] = 'S';
    trame1[17] = 'M';
    trame1[18] = 'o';
    trame1[19] = '6';
    trame1[20] = '1';
    trame1[21] = '5';
    trame1[22] = '2';
    trame1[23] = '0';
    trame1[24] = '6';
    trame1[25] = '8';
    trame1[26] = '-';
    trame1[27] = 'R';
    trame1[28] = '%';
    trame1[29] = '4';
    trame1[30] = '-';
    trame1[31] = 'T';
    trame1[32] = '5';
    trame1[33] = '1';
    trame1[34] = '.';
    trame1[35] = '5';
    trame1[36] = '-';
    trame1[37] = 'D';
    trame1[38] = 'T';
    trame1[39] = '2';
    trame1[40] = '0';
    trame1[41] = '2';
    trame1[42] = '1';
    trame1[43] = '/';
    trame1[44] = '0';
    trame1[45] = '3';
    trame1[46] = '/';
    trame1[47] = '3';
    trame1[48] = '1';
    trame1[49] = ' ';
    trame1[50] = '1';
    trame1[51] = '5';
    trame1[52] = ':';
    trame1[53] = '0';
    trame1[54] = '0';
    trame1[55] = ':';
    trame1[56] = '0';
    trame1[57] = '7';
    trame1[58] = '-';
    trame1[59] = 'B';
    trame1[60] = 'A';
    trame1[61] = 'T';
    trame1[62] = 'T';
    trame1[63] = '-';
    trame1[64] = 'C';
    trame1[65] = '9';
    trame1[66] = '6';
    trame1[67] = '-';
    trame1[68] = 'V';
    trame1[69] = '4';
    trame1[70] = '.';
    trame1[71] = '1';
    trame1[72] = '-';
    trame1[73] = 'A';
    trame1[74] = '1';
    trame1[75] = '2';
    trame1[76] = '9';
    trame1[77] = '5';
    trame1[78] = '-';
    trame1[79] = 'L';
    trame1[80] = 'O';
    trame1[81] = 'A';
    trame1[82] = 'D';
    trame1[83] = '-';
    trame1[84] = 'T';
    trame1[85] = '3';
    trame1[86] = '8';
    trame1[87] = '.';
    trame1[88] = '0';
    trame1[89] = '3';
    trame1[90] = '4';
    trame1[91] = 255;

    unsigned char trame2[44];

    trame2[0] = 1;
    trame2[1] = 39;
    trame2[2] = 'S';
    trame2[3] = 'T';
    trame2[4] = 'A';
    trame2[5] = 'T';
    trame2[6] = 'U';
    trame2[7] = 'S';
    trame2[8] = 2;
    trame2[9] = 2;
    trame2[10] = '-';
    trame2[11] = 'I';
    trame2[12] = 'N';
    trame2[13] = 'S';
    trame2[14] = 'T';
    trame2[15] = '-';
    trame2[16] = 'O';
    trame2[17] = 'N';
    trame2[18] = '-';
    trame2[19] = 'N';
    trame2[20] = 'O';
    trame2[21] = 'R';
    trame2[22] = 'M';
    trame2[23] = '-';
    trame2[24] = 'T';
    trame2[25] = '2';
    trame2[26] = '8';
    trame2[27] = '.';
    trame2[28] = '8';
    trame2[29] = '-';
    trame2[30] = 'C';
    trame2[31] = 'U';
    trame2[32] = 'B';
    trame2[33] = 'E';
    trame2[34] = '-';
    trame2[35] = 'T';
    trame2[36] = '1';
    trame2[37] = '9';
    trame2[38] = '7';
    trame2[39] = '.';
    trame2[40] = '4';
    trame2[41] = '0';
    trame2[42] = '9';
    trame2[43] = 255;

    string s = "";
    reponse->setTrame(trame1);
    reponse->identifierType();
    reponse->setTrame(trame2);
    reponse->identifierType();
    s = reponse->genererTrame();

    cout << s << endl;
}

void testSimpleMe()
{
    unsigned char trame[33];
    trame[0] = 1;
    trame[1] = 28;
    trame[2] = 'M';
    trame[3] = 'E';
    trame[4] = 'A';
    trame[5] = 'S';
    trame[6] = 'U';
    trame[7] = 'R';
    trame[8] = 'E';
    trame[9] = 1;
    trame[10] = 1;
    trame[11] = '-';
    trame[12] = 'T';
    trame[13] = 'C';
    trame[29] = ' ';
    trame[30] = 'C';
    trame[31] = '7';
    trame[32] = 255;

    string s;

    for (int y = 14; y <= 28; y = y + 5)
    {
        trame[y] = ' ';
        trame[y + 1] = (rand() % 10) + 48;
        trame[y + 2] = (rand() % 10) + 48;
        trame[y + 3] = '.';
        trame[y + 4] = (rand() % 10) + 48;
    }
    reponse->setTrame(trame);
    reponse->identifierType();
    s = reponse->genererTrame();

    cout << s << endl;
}

void testMatriceMe()
{
    unsigned char trame[59];
    trame[0] = 1;
    trame[1] = 54;
    trame[2] = 'M';
    trame[3] = 'E';
    trame[4] = 'A';
    trame[5] = 'S';
    trame[6] = 'U';
    trame[7] = 'R';
    trame[8] = 'E';
    trame[9] = 8;
    trame[10] = 1;
    trame[11] = '-';
    trame[12] = 'P';
    trame[13] = 'I';
    trame[14] = 'X';
    trame[55] = ' ';
    trame[56] = 'C';
    trame[57] = '7';
    trame[58] = 255;

    string s;
    for (int i = 1; i <= 8; i++)
    {
        for (int y = 15; y <= 54; y = y + 5)
        {
            trame[y] = ' ';
            trame[y + 1] = (rand() % 10) + 48;
            trame[y + 2] = (rand() % 10) + 48;
            trame[y + 3] = '.';
            trame[y + 4] = (rand() % 10) + 48;
        }
        trame[10] = i;
        reponse->setTrame(trame);
        reponse->identifierType();
        s = reponse->genererTrame();
    }
    cout << s << endl;
}

void testImageMe()
{
    unsigned char trame[NB_PIXEL_IMAGE];
    trame[0] = 1;
    trame[1] = 21;
    trame[2] = 'M';
    trame[3] = 'E';
    trame[4] = 'A';
    trame[5] = 'S';
    trame[6] = 'U';
    trame[7] = 'R';
    trame[8] = 'E';
    trame[9] = '-';
    trame[10] = 'I';
    trame[11] = 'M';
    trame[12] = 'G';
    trame[13] = ' ';
    trame[14] = '6';
    trame[15] = '5';
    trame[16] = '0';
    trame[17] = '8';
    trame[18] = '2';
    trame[19] = ' ';
    trame[20] = '1';
    trame[21] = '2';
    trame[22] = ' ';
    trame[23] = '7';
    trame[24] = 'C';
    trame[25] = 255;

    ifstream src("./test.jpg", ios::in | ios::binary);
    stringstream imageBrut;
    imageBrut << src.rdbuf();
    string image = imageBrut.str();
    string s;
    for (int i = 26, y = 0; y < image.size(); i++, y++)
    {
        if (i != (trame[1] + 5))
        {
            if ((i - (trame[1] + 5)) % 98 == 0)
            {
                trame[i] = '7';
                trame[i + 1] = 'C';
                i += 2;
            }
        }
        trame[i] = image[y];
    }
    reponse->setTrame(trame);
    reponse->identifierType();
    s = reponse->genererTrame();
    cout << s << endl;
}

void testSimpleMi()
{
    unsigned char trame[77];
    trame[0] = 1;
    trame[1] = 72;
    trame[2] = 'M';
    trame[3] = 'I';
    trame[4] = 'S';
    trame[5] = 'S';
    trame[6] = 'I';
    trame[7] = 'O';
    trame[8] = 'N';
    trame[9] = 1;
    trame[10] = 1;
    trame[11] = '-';
    trame[12] = 'T';
    trame[13] = 'C';
    trame[74] = 'C';
    trame[75] = '7';
    trame[76] = 255;

    string s;

    for (int y = 14; y < 74; y = y + 30)
    {
        trame[y] = ' ';
        trame[y + 1] = '-';
        trame[y + 2] = 'T';
        trame[y + 3] = (rand() % 10) + 48;
        trame[y + 4] = (rand() % 10) + 48;
        trame[y + 5] = '.';
        trame[y + 6] = (rand() % 10) + 48;
        trame[y + 7] = ' ';
        trame[y + 8] = '-';
        trame[y + 9] = 'D';
        trame[y + 10] = 'T';
        trame[y + 11] = '2';
        trame[y + 12] = '0';
        trame[y + 13] = '2';
        trame[y + 14] = '1';
        trame[y + 15] = '/';
        trame[y + 16] = '0';
        trame[y + 17] = '3';
        trame[y + 18] = '/';
        trame[y + 19] = '3';
        trame[y + 20] = '1';
        trame[y + 21] = ' ';
        trame[y + 22] = '1';
        trame[y + 23] = '5';
        trame[y + 24] = ':';
        trame[y + 25] = '0';
        trame[y + 26] = '0';
        trame[y + 27] = ':';
        trame[y + 28] = '0';
        trame[y + 29] = '7';
    }
    reponse->setTrame(trame);
    reponse->identifierType();
    s = reponse->genererTrame();

    cout << s << endl;
}

void testMatriceMi()
{
    unsigned char trame[81];
    trame[0] = 1;
    trame[1] = 54;
    trame[2] = 'M';
    trame[3] = 'I';
    trame[4] = 'S';
    trame[5] = 'S';
    trame[6] = 'I';
    trame[7] = 'O';
    trame[8] = 'N';
    trame[9] = 8;
    trame[10] = 1;
    trame[11] = '-';
    trame[12] = 'P';
    trame[13] = 'I';
    trame[14] = 'X';
    trame[55] = ' ';
    trame[56] = 'C';
    trame[57] = '7';
    trame[58] = 255;

    string s;
    for (int i = 1; i <= 8; i++)
    {
        for (int y = 15; y <= 54; y = y + 5)
        {
            trame[y] = ' ';
            trame[y + 1] = (rand() % 10) + 48;
            trame[y + 2] = (rand() % 10) + 48;
            trame[y + 3] = '.';
            trame[y + 4] = (rand() % 10) + 48;
        }
        trame[10] = i;
        if (trame[10] == trame[9])
        {
            trame[1] += 22;
            trame[56] = '-';
            trame[57] = 'D';
            trame[58] = 'T';
            trame[59] = '2';
            trame[60] = '0';
            trame[61] = '2';
            trame[62] = '1';
            trame[63] = '/';
            trame[64] = '0';
            trame[65] = '5';
            trame[66] = '/';
            trame[67] = '1';
            trame[68] = '5';
            trame[69] = ' ';
            trame[70] = '1';
            trame[71] = '1';
            trame[72] = ':';
            trame[73] = '3';
            trame[74] = '9';
            trame[75] = ':';
            trame[76] = '5';
            trame[77] = '2';
            trame[78] = '7';
            trame[79] = 'C';
            trame[80] = 255;
        }
        reponse->setTrame(trame);
        reponse->identifierType();
        s = reponse->genererTrame();
    }
    cout << s << endl;
}

void testImageMi()
{
    unsigned char trame[NB_PIXEL_IMAGE];
    trame[0] = 1;
    trame[1] = 43;
    trame[2] = 'M';
    trame[3] = 'E';
    trame[4] = 'A';
    trame[5] = 'S';
    trame[6] = 'U';
    trame[7] = 'R';
    trame[8] = 'E';
    trame[9] = '-';
    trame[10] = 'I';
    trame[11] = 'M';
    trame[12] = 'G';
    trame[13] = ' ';
    trame[14] = '6';
    trame[15] = '5';
    trame[16] = '0';
    trame[17] = '8';
    trame[18] = '2';
    trame[19] = ' ';
    trame[20] = '1';
    trame[21] = '2';
    trame[22] = ' ';
    trame[23] = '-';
    trame[24] = 'D';
    trame[25] = 'T';
    trame[26] = '2';
    trame[27] = '0';
    trame[28] = '2';
    trame[29] = '1';
    trame[30] = '/';
    trame[31] = '0';
    trame[32] = '5';
    trame[33] = '/';
    trame[34] = '1';
    trame[35] = '5';
    trame[36] = ' ';
    trame[37] = '1';
    trame[38] = '1';
    trame[39] = ':';
    trame[40] = '3';
    trame[41] = '9';
    trame[42] = ':';
    trame[43] = '5';
    trame[44] = '2';
    trame[45] = '7';
    trame[46] = 'C';
    trame[47] = 255;

    ifstream src("./test.jpg", ios::in | ios::binary);
    stringstream imageBrut;
    imageBrut << src.rdbuf();
    string image = imageBrut.str();
    string s;
    for (int i = 48, y = 0; y < image.size(); i++, y++)
    {
        if (i != (trame[1] + 5))
        {
            if ((i - (trame[1] + 5)) % 98 == 0)
            {
                trame[i] = '7';
                trame[i + 1] = 'C';
                i += 2;
            }
        }
        trame[i] = image[y];
    }
    reponse->setTrame(trame);
    reponse->identifierType();
    s = reponse->genererTrame();
    cout << s << endl;
}