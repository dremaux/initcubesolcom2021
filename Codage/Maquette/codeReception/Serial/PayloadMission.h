/* Boulanger Gabrielle-Anne
 * stoque la mission d'une trame
 * ligne de compilation :
 * création de 29/04/2020
 */
 
 #ifndef PAYLOADMISSION_H
 #define PAYLOADMISSION_H
 
 class PayloadMission : public Payload{
	 public:
		PayloadMission(char* payloadBrut);
	private:
		int periodicite;
		int duree;
		char* dateDebut;
		typeMesure typeMesure;
 };
#endif PAYLOADMISSION_H
