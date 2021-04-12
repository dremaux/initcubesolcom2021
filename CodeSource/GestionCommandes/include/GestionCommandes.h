

class GestionCommandes {
    public:

        GestionCommandes();
        ~GestionCommandes();
        
        int GetDCommandes(int nombreCommandes);  // Dernière commande
        void TDCommandes(); // transmettre dernière commande
    
    private:

        int DCommandes;

}