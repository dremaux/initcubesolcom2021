#ifndef COMINITCUBE_H
#define COMINITCUBE_H
#include <Serial.h>
#include <mutex>
using namespace std;

class ComInitCube
{
    private:
    string attendreAck();
    Serial* maLiaisonSerie;
	mutex* mtx;
    bool verifierChecksum(unsigned char* trame, int taille);
    void calculerChecksum( unsigned char* trame, unsigned char & PF, unsigned char & pf, int taille);

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
    void transmettreTrame(unsigned char* s);

    bool lireTrame(unsigned char* trame, int taille);

};

#endif
