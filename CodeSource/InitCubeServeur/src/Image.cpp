#include "Image.hpp"

using json = nlohmann::json;

ofstream myFile;

Image::Image()
{
}

void Image::extraireDonnee(char *trame, int nbOctetType)
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

bool Image::genererImage(string nom, int width, int height)
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

string Image::genererTrame(string nom, string typeMeasure, string type, string dt)
{
    json trame;

    trame[type]["name"] = nom;
    trame[type]["type mesure"] = typeMeasure;
    trame[type]["donnee"]["chemin"] = name;
    trame[type]["donnee"]["width"] = width;
    trame[type]["donnee"]["height"] = height;
    if (type == "mission")
    {
        trame[type]["date"] = dt;
    }
    return trame.dump();
}

Image::~Image()
{
}