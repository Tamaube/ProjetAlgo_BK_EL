#include "LecteurImage.h"

LecteurImage::LecteurImage()
{


    ifstream fichier("vigne", ios::in);

    if(fichier){
        int entier1, entier2;
        string chaine1;


        fichier >> chaine1 >> tailleX >> tailleY ;  /*on lit jusqu'à l'espace et on stocke ce qui est lu dans la variable indiquée */

        unsigned char bit;
        tabPixels = malloc(sizeof(void *)*tailleX*tailleY);

        for (unsigned int j = 0; j < tailleY; j++) {
            for (unsigned int i = 0; i < tailleX; i++) {

                fichier >> bit;
                if(bit == O) {
                    Pixel tabPixels[i*j] = new Pixel(i, j);
                }else {
                    tabPixels[i*j] = nullptr;
                }
            }
        }

    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;

    return 0;
}

LecteurImage::~LecteurImage()
{
    fichier.close();
}
