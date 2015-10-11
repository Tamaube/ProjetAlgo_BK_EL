#ifndef LECTEURIMAGE_H
#define LECTEURIMAGE_H
#include "Pixel.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class LecteurImage
{



    public:
        LecteurImage();
        ~LecteurImage();
        void lireMetaDonnees();
    protected:
    private:
        unsigned int tailleX;
        unsigned int tailleY;
        Pixel **tabPixels;
        ifstream fichier;
};

#endif // LECTEURIMAGE_H
