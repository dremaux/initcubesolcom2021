#include <boost/asio.hpp>

#ifndef COMINIT_H
#define COMINIT_H

class ComInit
{
    private:
    void attendreAck();
    boost::asio::io_service io;
    boost::asio::serial_port serial;

    public:

    /**
     * ///Constructeur
     * paramètre "port": nom du Device -> "/dev/ttyUSB0" ou "/dev/ttyS0"
     * paramètre "baud_rate": vitesse de transmission(baud) -> 9600, 19200 ou 115200
     * génère exception "boost::system:system_error" si port série pas ouvrable.
    **/
    ComInit(std::string port, unsigned int baud_rate);

    /**
     * /// Ecrit une chaine de caratères à transmettre
     * paramètre "s": chaine de caractères que l'on veut transmettre
     * génère une exception "boost::system::system_error" si erreur
    **/
    void transmettreTrame(std::string s);

};

#endif
