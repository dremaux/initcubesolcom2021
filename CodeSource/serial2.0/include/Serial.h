/// Les Inclusions
#include <boost/asio.hpp>

#ifndef SERIAL_H
#define SERIAL_H

class Serial
{
    private:
    boost::asio::io_service io;
    boost::asio::serial_port serial;

    public:
    /**
     * ///Constructeur
     * paramètre "port": nom du Device -> "/dev/ttyUSB0" ou "/dev/ttyS0"
     * paramètre "baud_rate": vitesse de transmission(baud) -> 9600, 19200 ou 115200
     * génère exception "boost::system:system_error" si port série pas ouvrable.
    **/
    Serial(std::string port, unsigned int baud_rate);
    
    /**
     * /// Ecrit une chaine de caratères à transmettre
     * paramètre "s": chaine de caractères que l'on veut transmettre
     * génère une exception "boost::system::system_error" si erreur
    **/
   void writeString(std::string s);

    /**
     * Méthode blocante jusqu'à ce qu'on reçoive une ligne(trame) sur le port série
     * la méthode rend la main dès qu'elle reçoit un retour chariot("\n")
     * génère une exception boost::system::system_error en cas d'erreur
    **/
   std::string readLine();
};

#endif /* SERIAL_H */