#include "Image.hpp"

ofstream myFile;



Image::Image() {
    
    security = false;
    compteurL = 1;
    compteurS = 1;
    iterateur = 0;
}

void Image::extraireDonnee(unsigned char* trame, int nbOctetType){
    if(trame[NUM_LIGNE] == compteurL && trame[NUM_SECTION] == compteurS){
        security = false;
        caseFinM = trame[2] + 2;
        caseDebutM = DEBUT_TRAME_IMAGE + nbOctetType;
        if(trame[NUM_LIGNE] == 1 && trame[NUM_SECTION] == 1){
            for(int i = 0;i<NB_PIXEL_IMAGE;i++){
                donneeExtraite[i] = 0;
            }    
        }

        if(trame[NBRE_LIGNES] == trame[NUM_LIGNE] && trame[NBRE_SECTION] == trame[NUM_SECTION]){
            compteurL = 1;
            compteurS = 1;//reset des compteur
            for(int i = caseDebutM + 1; i <= caseFinM;i++){ //le +1 est la pour ignorer le premier espace 
                donneeExtraite[iterateur] = trame[i];
                iterateur ++;
            }
            iterateur = 0;
        }
        else if(trame[NBRE_SECTION] == trame[NUM_SECTION]){
            compteurS = 1;//reset du compteur
            compteurL ++;
            for(int i = caseDebutM+1; i <= caseFinM;i++){ //le +1 est la pour ignorer le premier espace 
                donneeExtraite[iterateur] = trame[i];
                iterateur ++;
            }
        }
        else{
            compteurS ++;
            for(int i = caseDebutM+1; i <= caseFinM;i++){ //le +1 est la pour ignorer le premier espace 
                donneeExtraite[iterateur] = trame[i];
                iterateur ++;
            }
        }
    }else{
        cout<<"trame precedente non complete"<<endl;
        security = true;
        if(trame[NUM_LIGNE] == 1 && trame[NUM_SECTION] == 0){
            cout<<"debut nouvelle trame abandon de la precedente"<<endl;
            compteurL = 1;
            compteurS = 1;
            extraireDonnee(trame,nbOctetType);
        }
    }
} 

void myOutput(unsigned char byte){
    
    myFile << byte;
}

bool Image::genereImage(string nom, int width, int height){
    nom = "./images/"+nom+".jpg";
    name = nom;
    this->width = width;
    this->height = height;
    myFile.open(nom, std::ios_base::out | std::ios_base::binary);
    // RGB: one byte each for red, green, blue
    const auto bytesPerPixel = 3;
    // allocate memory
    auto image = new unsigned char[width * height * bytesPerPixel];
    // create a nice color transition (replace with your code)
    int i = 0;
    for (auto y = 0; y < height; y++)
        for (auto x = 0; x < width; x++)
        {
        // memory location of current pixel
        auto offset = (y * width + x) * bytesPerPixel;
        image[offset    ] = donneeExtraite[i];
        i++;
        image[offset + 1] = donneeExtraite[i];
        i++;
        image[offset + 2] = donneeExtraite[i];
        i++;
    }
    // start JPEG compression
    // note: myOutput is the function defined in line 18, it saves the output in example.jpg
    // optional parameters:
    const bool isRGB      = true;  // true = RGB image, else false = grayscale
    const auto quality    = 90;    // compression quality: 0 = worst, 100 = best, 80 to 90 are most often used
    const bool downsample = false; // false = save as YCbCr444 JPEG (better quality), true = YCbCr420 (smaller file)
    const char* comment = "Picture from initcubevol"; // arbitrary JPEG comment
    auto ok = TooJpeg::writeJpeg(myOutput, image, width, height, isRGB, quality, downsample, comment);
    delete[] image;
    // error => exit code 1
    return ok ? 0 : 1;
}

string Image::genereTrame(string nom, string typeMeasure, string type, string dt){
    json trame;
    if(compteurL == 1 && compteurS == 1 && security == false){
        trame[type]["name"] = nom;
        trame[type]["type mesure"] = typeMeasure;
        trame[type]["donnee"]["chemin"] = name;
        trame[type]["donnee"]["width"]= width;
        trame[type]["donnee"]["height"]= height;
        if(type == "mission"){
            trame[type]["date"] = dt;
        }
        return trame.dump();
    }
    else{
        cout<<"trame precedente pas fini"<<endl;
        return "";
        
    }
}

Image::~Image() {

}