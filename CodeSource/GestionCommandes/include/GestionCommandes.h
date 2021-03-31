#include <iostream>
#include "DernieresCommandes.h"

using namespace std;

class GestionCommandes {
    public:

        GestionCommandes();
        ~GestionCommandes();
        

        void transmettreDernieresCommandes();
        DCommandes getDerieresCommandes(int nombreCommande);

    private:

       DCommandes ;


}