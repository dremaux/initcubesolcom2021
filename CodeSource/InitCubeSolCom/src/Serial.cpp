#include "Serial.h"
#include <iostream>

using namespace boost::asio;

/**
     * Constructeur.
     * \paramètre port : nom du device, exemple "/dev/ttyUSB0" ou "/dev/ttyAMA0" sous R-Pi
     * \paramètre baud_rate : vitesse de transmission en baud, example 9600, 19200 ou 115200
     * \génère une exception boost::system::system_error si le port série ne peut pas être ouvert
     */
Serial::Serial(std::string port, unsigned int baud_rate)
    : io(), serial(io, port)
{
    serial.set_option(serial_port_base::baud_rate(baud_rate));
}

/**
     * Ecrit une chaîne de caractères sur le port série.
     * paramètre "s" : chaîne de caractères à transmettre
     * Génère une exception boost::system::system_error en cas d'erreur
     */
void Serial::writeChar(unsigned char* message, int taille)
{
    std::cout<<taille<<std::endl;
    for(int i = 0; i < taille; i++){
        std::cout<<message[i];
    }
    std::cout<<std::endl;
    write(serial, boost::asio::buffer(message, taille));
}

unsigned char Serial::readChar(){
    
    unsigned char c;
    read(serial, buffer(&c, 1));
    return c;
}