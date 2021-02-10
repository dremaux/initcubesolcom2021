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
     * Constructeur.
     * \paramètre port : nom du device, exemple "/dev/ttyUSB0" ou "/dev/ttyAMA0" sous R-Pi
     * \paramètre baud_rate : vitesse de transmission en baud, example 9600, 19200 ou 115200
     * \génère une exception boost::system::system_error si le port série ne peut pas être ouvert
     */
    Serial(std::string port, unsigned int baud_rate);

    /**
     * Ecrit une chaîne de caractère sur le port série.
     * \paramètre s : chaîne de caractère à transmettre
     * \génère une exception boost::system::system_error en cas d'erreur
     */
    void writeString(std::string s);
    /**
     * Méthode blocante jusqu'à réception d'une ligne (ou trame) sur le port série
     * la méthode rend la main à réception d'un caractère retour chariot ('\r')
     * et retourne la ligne reçue sous forme d'une chaîne de caractère
     * \génère une exception boost::system::system_error en cas d'erreur
     */
    std::string readLine();

};

#endif /* SERIAL_H */
