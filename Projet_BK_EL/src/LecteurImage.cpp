#include "LecteurImage.h"

LecteurImage::LecteurImage()
{


    ifstream fichier("vigne", ios::in);

    if(fichier){


        lireMetaDonnees ();

        unsigned char bit;
        tabPixels = (Pixel**) malloc(sizeof(void *)*tailleX*tailleY);

        for (unsigned int j = 0; j < tailleY; j++) { // "j" représente le numéro de la ligne (variable en Y)
            for (unsigned int i = 0; i < tailleX; i++) { // "j" représente le numéro de la colonne (variable en X)

                fichier >> bit;
                if(bit == 0) {
                    Pixel tabPixels[i + (tailleX * j)] = new Pixel(i, j);
                }else {
                    tabPixels[i*j] = nullptr;
                }
            }
        }

    } else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

LecteurImage::~LecteurImage()
{
    fichier.close();
}


void LecteurImage::lireMetaDonnees() {

        string chaine1;
        fichier >> chaine1 ;                    /* On lit le premier champ qui correspond à au type de données*/
        fichier >> tailleX ;                    /* On lit la taille horizontale du tableau */
        fichier >> tailleY ;                    /* On lit la taille vertical du tableau */

}
