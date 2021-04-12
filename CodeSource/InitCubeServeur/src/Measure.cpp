#include "Measure.hpp"

Measure::Measure(){

}

Measure::Measure(string trame):trame(trame) {

}

void Measure::identifierType(){
    if(trame.find("MEASURE") > 0 ){
        int debut = trame.find('-')+1;//+1 pour ignorer le -
        int fin = trame.find(' ');
        type = trame.substr(debut,(fin - debut));
    }
    else{
        perror("ce n'est pas une trame measure");
    }
}

void Measure::setTrame(string trame){
    this->trame = trame;
}

string Measure::genererTrame(){
    
}

Measure::~Measure() {

}