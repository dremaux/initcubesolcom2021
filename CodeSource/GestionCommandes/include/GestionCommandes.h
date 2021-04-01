
class GestionCommandes {
    public:

        GestionCommandes();
        ~GestionCommandes();
        
        int GetDCommandes(int nombreCommandes);
        void transmettreDernieresCommandes();
    
    private:

        int DCommandes;

}