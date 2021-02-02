/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: snir2g2
 *
 * Created on 5 mars 2020, 13:39
 */

#include <cstdlib>
#include "ServeurCommande.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char buffer[1024];
    
    ServeurCommande* monServeur = new ServeurCommande();
    monServeur->attendreConnexion();
    monServeur->recevoir(buffer, 1024);
    cout << "Message reçu : " << buffer << endl;
    return 0;
}

