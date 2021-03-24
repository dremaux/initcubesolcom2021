#include <iostream>
#include "../include/ComInit.h"
#include "../include/Serial.h"

/*using namespace std;

int transmettreTrame()
{
    string message;
    Serial maLiaisonSerie("/dev/ttyS0",9600);

    message = maLiaisonSerie.writeString(std::string s);
    cout << "Envoi du message : " << message << endl;
    return 0;
}
*/

    /**
    * ---Constructeur---
    * \paramètre port : nom du device, exemple "/dev/ttyUSB0" ou "/dev/ttyAMA0" sous R-Pi
    * \paramètre baud_rate : vitesse de transmission en baud, example 9600, 19200 ou 115200
    * \génère une exception boost::system::system_error si le port série ne peut pas être ouvert
    **/
   void ComInit::transmettreTrame(std::string s)
    {
        boost::asio::write(serial,boost::asio::buffer(s.c_str(),s.size()));
    }