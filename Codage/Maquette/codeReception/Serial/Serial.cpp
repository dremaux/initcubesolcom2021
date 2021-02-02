#include "Serial.h"


    /**
     * Constructeur.
     * \paramètre port : nom du device, exemple "/dev/ttyUSB0" ou "/dev/ttyAMA0" sous R-Pi
     * \paramètre baud_rate : vitesse de transmission en baud, example 9600, 19200 ou 115200
     * \génère une exception boost::system::system_error si le port série ne peut pas être ouvert
     */
    Serial::Serial(std::string port, unsigned int baud_rate)
    : io(), serial(io,port)
    {
        serial.set_option(boost::asio::serial_port_base::baud_rate(baud_rate));
    }

    /**
     * Ecrit une chaîne de caractère sur le port série.
     * \paramètre s : chaîne de caractère à transmettre
     * \génère une exception boost::system::system_error en cas d'erreur
     */
    void Serial::writeString(std::string s)
    {
        boost::asio::write(serial,boost::asio::buffer(s.c_str(),s.size()));
    }

    /**
     * Méthode blocante jusqu'à réception d'une ligne (ou trame) sur le port série
     * la méthode rend la main à réception d'un caractère retour chariot ('\r')
     * et retourne la ligne reçue sous forme d'une chaîne de caractère
     * \génère une exception boost::system::system_error en cas d'erreur
     */
    std::string Serial::readLine()
    {
        
        using namespace boost;
        char c;
        std::string result;
        for(;;)
        {
			//lecture caractère par caractère            
			asio::read(serial,asio::buffer(&c,1));
			//retour de la chaîne de caractère coplète en cas de réception du retour chariot			
			if (c=='\n')
				return result;
			//sinon ajout du carctère reçu à la chaiîne de caractère.		
			else
				result+=c;	
        }
    }


