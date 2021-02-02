/* Boulanger Gabrielle-Anne
 * classe qui ....
 * ligne de compilation :
 * fait le 29/04/2020
 */


#ifndef PAYLOAD_H
#define PAYLOAD_H

#define TAILLE_PAYLOAD 48

class Payload {
	public :
		virtual void extraireInformations();	//Déclaration de la méthode virtuelle pure d'extraxtion d'informations
		Payload(char* payloadBrut); 		//Déclaration du constructeur
		virtual ~Payload();			//Déclaration du destructeur
	private :
		char payloadBrut[TAILLE_PAYLOAD]; 	//Déclaration du tableau
		int numeroPaquet;			//Déclaration d'une variable ..... 
};

#endif /* PAYLOAD_H */
