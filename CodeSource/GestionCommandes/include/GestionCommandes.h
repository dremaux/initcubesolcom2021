#include <iostream>

using namespace std;

class GestionCommandes {
    public:

        GestionCommandes();
        ~GestionCommandes();
        
        void transmettreDerniereCommandes();
        DerniereCommandes getDerniereCommandes();


    private:

        DerniereCommandes etat;        


}