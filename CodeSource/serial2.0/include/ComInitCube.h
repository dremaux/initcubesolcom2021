#ifndef COMINITCUBE_H
#define COMINITCUBE_H
#include <Serial.h>
#include <timercpp.h>


class ComInitCube
{
    private:
    bool attendreAck();
    Serial* maLiaisonSerie;
    void verifierChecksum();

    public:

    /**
     * ///Constructeur
     * paramètre "port": nom du Device -> "/dev/ttyUSB0" ou "/dev/ttyS0"
     * paramètre "baud_rate": vitesse de transmission(baud) -> 9600, 19200 ou 115200
     * génère exception "boost::system:system_error" si port série pas ouvrable.
    **/
    ComInitCube(std::string port, unsigned int baud_rate);

    /**
     * /// Ecrit une chaine de caratères à transmettre
     * paramètre "s": chaine de caractères que l'on veut transmettre
     * génère une exception "boost::system::system_error" si erreur
    **/
    void transmettreTrame(std::string s);

    void lireTrame(std::string s);

};

#endif
