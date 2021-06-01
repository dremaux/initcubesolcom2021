#include "Serial.h"

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
void Serial::writeString(char* s, int taille)
{
    write(serial, boost::asio::buffer(s, taille));
}

/**
     * Méthode blocante jusqu'à réception d'une ligne (ou trame) sur le port série
     * la méthode rends la main quand elle reçois un caractère "255"
     * et retourne la ligne reçue sous forme d'une chaîne de caractères
     * Génère une exception boost::system::system_error en cas d'erreur
     */
std::string Serial::readLine()
{

    
    char c;
    std::string result;
    int retour;

    for (;;)
    {
        //lecture caractère par caractère
        retour = read(serial, buffer(&c, 1));
        //retour de la chaîne de caractère complète en cas de réception de "255"
        if (retour != 0)
        {
            if (c == 255)//passage en paramettre
            {
                result = resultat;
                resultat = "";
                return result;
            }
            //sinon ajout du carctère reçu à la chaîne de caractères
            else
                resultat += c;
        }
        else
        {
            return "FIN";
        }
    }
}

int Serial::wait(int s)
{
    using namespace boost::asio;
    io_service i;
    deadline_timer t(i);
    t.expires_from_now(boost::posix_time::seconds(s));
    t.wait();
    return 0;
}

char Serial::readChar(){
    
    char c;
    read(serial, buffer(&c, 1));
    return c;
}