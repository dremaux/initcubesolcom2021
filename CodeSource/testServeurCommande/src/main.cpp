#include "ServeurTransmitionCommande.hpp"
#include "Commande.hpp"
#include <thread>
#include <iostream>

ServeurTransmitionCommande *serveurEcouteJTP = new ServeurTransmitionCommande(9954);

int numMap = 0;
void attenteCommande();
void nouveauClient();
void traitementCommande();
int main()
{
	thread *monThreadAttente = new thread(attenteCommande);
	thread *monThreadAffichage = new thread(traitementCommande);

	monThreadAffichage->join();
	monThreadAttente->join();
	return 0;
}

void attenteCommande()
{
	while (1)
	{
		numMap = serveurEcouteJTP->attendreConnexion();
		if (numMap >= 0)
		{
			thread *monThreadClient = new thread(nouveauClient);
		}
	}
}

void nouveauClient()
{
	int numMapC = numMap;
	int retour = 0;
	while (retour >= 0)
	{
		retour = serveurEcouteJTP->attendreCommande(numMapC);
	}
}

void traitementCommande(){
	Commande *commande = new Commande();
	unsigned char trameF[110];
    while (1)
    {
        if (!serveurEcouteJTP->getRecu().empty())
        {
            for (int i = 0; i < 110; i++)
            {
                trameF[i] = 0;
            }
            bool set = commande->setTrame(serveurEcouteJTP->getRecu().front());
            serveurEcouteJTP->effacerPremierRecu();
            if (set && commande->extraireDonnees() > 0)
            {
                bool com = commande->genererTrame(trameF);

                if (com)
                {
                    for(int y = 0; y < 110;y++){
						std::cout<<trameF[y];
					}
					std::cout<<std::endl;
                }
            }
        }
    }
}