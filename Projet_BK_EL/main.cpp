#include <iostream>
#include "LecteurImage.h"
#include "testWriteFic.h"


using namespace std;

void lire_tableau_pixel(LecteurImage* l){


    cout << "== Affichage du tableau de pixel " << endl;

    Pixel* tabP = l->tabPixels;

    unsigned int Dimension_X = l->tailleX;  //Nombre de pixel en horizontal
    unsigned int Dimension_Y = l->tailleY;  //Nombre de pixel en vertical

    cout << "Dimension du tableau : " << Dimension_X << " par " << Dimension_Y << endl<< endl;


    unsigned int case_du_tab;
    Pixel* pixel_traite = (Pixel*)malloc(sizeof(Pixel));
    bool pixel_noir;
    for (unsigned int ligne = 0; ligne < Dimension_Y; ligne++){
        cout << ligne << "\t(";
        for (unsigned int col = 0; col < Dimension_X; col++) {
            if (tabP[col + ligne*Dimension_X].pixelNoir) {
                cout <<  "1 ";
            }else {
                cout <<  "0 ";
            }
        }
        cout << ")" << endl;
    }
}

void test_LecteurImage(){

    LecteurImage* l = new LecteurImage();
    lire_tableau_pixel(l);
    l = nullptr;

}
int main()
{
//    testEcriture();
    cout << "Alex est le mal dominant" << endl;

    test_LecteurImage();

    return 0;
}

