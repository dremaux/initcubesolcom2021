#include <cstdlib>
#include <string>
#include <stdio.h>
#include <iostream>
#include "tinyxml2.h"
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;
using namespace tinyxml2;

string titre = "* XML X-TRACTOR * \n";

int save() {
    XMLDocument doc;
    string saveFile;

    string sauvegarde;
    cout << "Sauvegarder le document ? Oui/Non" << endl;
    cin >> sauvegarde;

    if (sauvegarde == "oui" | sauvegarde == "Oui" | sauvegarde == "o") {
        system("clear");
        //faire printer bidule
        cout << "Veuillez rentrer un nom pour la sauvegarde" << endl;
        cin >> saveFile;

        system("clear");

        doc.SaveFile(saveFile.c_str(), false);

        cout << "Sauvegarde en cours..." << endl;
        sleep(5);
    } else if (sauvegarde == "non" | sauvegarde == "Non" | sauvegarde == "n") {
        cout << "" << endl;
    }
    else {
        system("clear");
        cout << "Merci de rentrer une réponse valide." << endl;
        cout << "" << endl;
        save();
    }
    return 0;
}

int main() {

    system("clear");
    
    XMLDocument doc;

    cout << titre << endl;

    cout << "Veuillez renseigner le nom du fichier à extraire." << endl;

    string fichier;
    string nomFichier;

    cin >> fichier;
    nomFichier += fichier;
    nomFichier += ".xml";

    if (!(cin.fail())) { //faire en sorte que si l'input est invalide ça remette au main en boucle

        doc.LoadFile(nomFichier.c_str());

        cout << " " << endl;
 
            doc.LoadFile(nomFichier.c_str());

            system("clear");

            string instrument = doc.FirstChildElement("initcube")->FirstChildElement("instrument")->Value();

            cout << instrument << endl;
            cout << "" << endl;

            string idInstrument = doc.FirstChildElement("initcube")->FirstChildElement("instrument")->FirstChildElement("description")->FirstChildElement("id")->GetText();
            string typeInstrument = doc.FirstChildElement("initcube")->FirstChildElement("instrument")->FirstChildElement("description")->FirstChildElement("type")->GetText();
            string roleInstrument = doc.FirstChildElement("initcube")->FirstChildElement("instrument")->FirstChildElement("description")->FirstChildElement("role")->GetText();


            string mesure1 = doc.FirstChildElement("initcube")->FirstChildElement("instrument")->FirstChildElement("mesure")->FirstAttribute()->Value();

            cout << "* Description : " << endl;
            cout << " " << endl;

            cout << "* ID : " << idInstrument << endl;
            cout << "* Type : " << typeInstrument << endl;
            cout << "* Role : " << roleInstrument << endl;

            cout << "" << endl;
            cout << "* Etat : " << endl;
            cout << "" << endl;

            string etatActif = doc.FirstChildElement("initcube")->FirstChildElement("instrument")->FirstChildElement("etat")->FirstChildElement("actif")->GetText();
            string etatTempUnite = doc.FirstChildElement("initcube")->FirstChildElement("instrument")->FirstChildElement("etat")->FirstChildElement("temperature")->FirstAttribute()->Value();
            string etatTempAlerteHaut = doc.FirstChildElement("initcube")->FirstChildElement("instrument")->FirstChildElement("etat")->FirstChildElement("temperature")->FindAttribute("SeuilALerteHaut")->Value();
            string etatTempAlerteBas = doc.FirstChildElement("initcube")->FirstChildElement("instrument")->FirstChildElement("etat")->FirstChildElement("temperature")->FindAttribute("SeuilALerteBas")->Value();
            string etatTemp = doc.FirstChildElement("initcube")->FirstChildElement("instrument")->FirstChildElement("etat")->FirstChildElement("temperature")->GetText();


            cout << "* Etat Actif : " << etatActif << endl;
            cout << "* Unité température : " << etatTempUnite << endl;
            cout << "* Seuil alerte température haut : " << etatTempAlerteHaut << endl;
            cout << "* Seuil alerte température bas : " << etatTempAlerteBas << endl;
            cout << "* Température : " << etatTemp << endl;

            cout << " " << endl;

        save();

    } else if (cin.fail()) {
        main();
    }

    system("clear");
    cout << "Merci d'avoir utilisé XML X-TRACTOR !" << endl;
    
    cout << "" << endl;
    
    XMLPrinter printer();
    doc.Print();
    return 0;
}


/*
 
 main : entrer nom fichier a extraire -
 
 boucle while tant que y a des nodes > choper valeurs 
 et / ou texte et le mettre dans un fichier
 
 
 
 
 */