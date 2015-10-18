#ifndef LECTEURIMAGE_H
#define LECTEURIMAGE_H
#include "Pixel.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class LecteurImage
{



    public:
        LecteurImage(string nomImage);
        ~LecteurImage();
        void lireMetaDonnees();
        unsigned int tailleX;   //Nombre de pixel en horizontal
        unsigned int tailleY;   //Nombre de pixel en vertical
        Pixel** tabPixels;
    protected:
    private:
        ifstream fichier;
};

#endif // LECTEURIMAGE_H
