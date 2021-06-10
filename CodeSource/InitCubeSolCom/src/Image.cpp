#include "Image.hpp"

ofstream myFile;

Image::Image()
{
}

void Image::extraireDonnee(unsigned char *trame, int nbOctetType)
{
    for (int i = 0; i < NB_PIXEL_IMAGE; i++)
    {
        donneeExtraite[i] = 0;
    }
    for (int i = (trame[1] + 5), y = 0; i < NB_PIXEL_IMAGE; i++, y++)
    {
        if (i != (trame[1] + 5))
        {
            if ((i - (trame[1] + 5)) % 98 == 0) //permet d'ignorer les checksums
            {
                i += 2;
            }
        }
        donneeExtraite[y] = trame[i];
    }
}

bool Image::genererImage(std::string nom, int width, int height)
{
    nom = "./images/" + nom + ".jpg";
    name = nom;
    this->width = width;
    this->height = height;
    myFile.open(nom, ios::out | ios::binary);
    for (int i = 0; i < NB_PIXEL_IMAGE; i++)
    {
        myFile << donneeExtraite[i];
    }
    myFile.close();
    return 0;
}

std::string Image::genererTrame(std::string nom, std::string typeMeasure, std::string type, std::string dt)
{
    json trame;

    trame[type]["type"] = nom;
    trame[type]["code"] = typeMeasure;
    trame[type]["donnees"]["chemin"] = name;
    trame[type]["donnees"]["largeur"] = width;
    trame[type]["donnees"]["hauteur"] = height;
    if (type == "mission")
    {
        trame[type]["date"] = dt;
    }
    return trame.dump();
}

Image::~Image()
{
}