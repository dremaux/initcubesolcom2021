#include "mongoInclude.h"

class GestionCommandes {
    public:

        GestionCommandes();
        ~GestionCommandes();
        
        int getDernieresCommandes(int nombreCommandes);  //affiche les Dernieres commandes
        int tDCommandes(); // transmettre les dernieres commandes
        int rechercheCommandes(int date); //trouve une trame grâce à la date
    
    private:

        GestionCommandes * gCommandes;

        int getDernieresCommandes;

        mongocxx::instance instance{};
        moncocxx::client client{mongocxx::uri{}};

        mongocxx::database db = client["initcube"];
        mongocxx::collection coll = db["commande"];

}