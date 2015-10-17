#include <iostream>
#include "LecteurImage.h"
#include "testWriteFic.h"
#include "WriteFic.h"
#include "Pixel.h"
#include "Ensemble.h"


using namespace std;

Pixel* TableauPixels;
unsigned int Dimension_X;
unsigned int Dimension_Y;



void lire_tableau_pixel(LecteurImage* l){


    cout << "== Affichage du tableau de pixel " << endl;

    TableauPixels = l->tabPixels;

    Dimension_X = l->tailleX;  //Nombre de pixel en horizontal
    Dimension_Y = l->tailleY;  //Nombre de pixel en vertical

    cout << "Dimension du tableau : " << Dimension_X << " par " << Dimension_Y << endl<< endl;


/*  //Affichage du contenu du tableau
    for (unsigned int ligne = 0; ligne < Dimension_Y; ligne++){
        cout << ligne << "\t(";
        for (unsigned int col = 0; col < Dimension_X; col++) {
            if (TableauPixels[col + ligne*Dimension_X].pixelNoir) {
                cout <<  "1 ";
            }else {
                cout <<  "0 ";
            }
        }
        cout << ")" << endl;
    }
    */
}

void test_LecteurImage(){

    LecteurImage* l = new LecteurImage("vigne.pbm");
    lire_tableau_pixel(l);
    l = nullptr;

}

void Algorithme_Union(){


    for (unsigned int ligne = 0; ligne < Dimension_Y; ligne++) {
        for (unsigned int colonne = 0; colonne < Dimension_X; colonne++) {






        }
    }



}

int main()
{
    cout << "Alex est le mal dominant" << endl;

    test_LecteurImage();







    WriteFic *wf = new WriteFic();
    wf->generate(5,5);
    return 0;
}

