#include <iostream>
#include "DernieresCommandes.h"

using namespace std;

class GestionCommandes {
    public:

        GestionCommandes();
        ~GestionCommandes();
        
        getDerieresCommandes(int nombreCommandes);
        void transmettreDernieresCommandes();

}