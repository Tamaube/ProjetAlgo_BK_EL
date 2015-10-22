#include "Pixel.h"
#include <iostream>

using namespace std;

void AfficheTableauPixel(Pixel** tabPixel, unsigned int Dimension_X,unsigned int Dimension_Y ) {
    for (unsigned int ligne = 0; ligne < Dimension_Y; ligne++){
        cout << ligne << "\t(";
        for (unsigned int col = 0; col < Dimension_X; col++) {
            if (tabPixel[col + ligne*Dimension_X]->pixelNoir) {
                cout <<  "1 ";
            }else {
                cout <<  "0 ";
            }
        }
        cout << ")" << endl;
    }

}
