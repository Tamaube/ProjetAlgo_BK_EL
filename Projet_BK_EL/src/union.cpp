#include "union.h"

void algo_union(Pixel** tableauPixels, unsigned int Dimension_X, unsigned int Dimension_Y)throw(string){
    unsigned int num_pixel_courant;
    Pixel* pixel_courant;
    for (unsigned int ligne = 0; ligne < Dimension_Y; ligne++) {
        for (unsigned int colonne = 0; colonne < Dimension_X; colonne++) {
            num_pixel_courant = ligne*Dimension_X + colonne;
            pixel_courant = tableauPixels[num_pixel_courant];
            if (!(ligne==0)) {//si il y a un pixel au dessus
                pixel_courant->propageCouleur(tableauPixels[(ligne-1)*Dimension_X + colonne]);
            }
            if (!(ligne==(Dimension_Y-1))) {//si il y a un pixel en dessous
                pixel_courant->propageCouleur(tableauPixels[(ligne+1)*Dimension_X + colonne]);
            }
            if (!(colonne==(Dimension_X-1))) {//si il y a un pixel à droite
                pixel_courant->propageCouleur(tableauPixels[ligne*Dimension_X + colonne+1]);
            }
        }
    }
}
