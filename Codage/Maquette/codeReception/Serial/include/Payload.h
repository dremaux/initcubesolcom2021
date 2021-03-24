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

#endif
