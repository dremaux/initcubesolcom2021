#ifndef PAYLOADMESURE_H
#define PAYLOADMESURE_H
 
#include "Payload.h"
#include "TypeMesure.h"

 class PayloadMesure : public Payload {
	 public:
		PayloadMesure();
		PayloadMesure(char* payloadBrut);
		virtual void extraireInformations();
		virtual ~PayloadMesure();
	 private:
		int nombrePaquet;
		int numeroPaquet;
		TypeMesure typeMesure;
		
 };
#endif
