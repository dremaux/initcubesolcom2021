#ifndef PAYLOADMISSION_H
#define PAYLOADMISSION_H
 
 #include "TypeMesure.h"

 class PayloadMission{ //: public Payload{
	public:
		PayloadMission(char* payloadBrut);
		~PayloadMission();
	private:
		int periodicite;
		int duree;
		char* dateDebut;
		TypeMesure typeMesure;
 };
#endif
