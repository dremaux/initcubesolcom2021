/// Les inclusions
#include "../include/Serial.h"
#include <iostream>

using namespace boost::asio;


Serial::Serial(std::string port, unsigned int baud_rate)
    : io(), serial(io, port)
{
    serial.set_option(serial_port_base::baud_rate(baud_rate));
}


void Serial::writeChar(unsigned char* message, int taille)
{
    write(serial, boost::asio::buffer(message, taille));
}


unsigned char Serial::readChar(){
    
    unsigned char c;
    read(serial, buffer(&c, 1));
    return c;
}