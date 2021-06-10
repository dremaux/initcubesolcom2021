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
     * /// Constructeur
     * 
     * Paramètre "port": nom du Device -> "/dev/ttyAMA0" ou "/dev/ttyS0"
     * Paramètre "baud_rate": vitesse de transmission(baud) -> 9600, 19200 ou 115200
     */
    Serial(std::string port, unsigned int baud_rate);

    /**
     * /// Ecrit une chaine de caratères à transmettre
     * 
     * Paramètre "s": chaine de caractères que l'on veut transmettre
     */
   void writeChar(unsigned char* message, int taille);

   unsigned char readChar();

};
#endif /* SERIAL_H */ 