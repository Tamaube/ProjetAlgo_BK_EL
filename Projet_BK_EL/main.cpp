#include <iostream>
#include "LecteurImage.h"
#include "testWriteFic.h"
#include "WriteFic.h"
#include "Pixel.h"
#include "Ensemble.h"


using namespace std;

Pixel** tableauPixels;
unsigned int Dimension_X;
unsigned int Dimension_Y;



void lire_tableau_pixel(LecteurImage* l){


    cout << "== Affichage du tableau de pixel " << endl;

    tableauPixels = l->tabPixels;

    Dimension_X = l->tailleX;  //Nombre de pixel en horizontal
    Dimension_Y = l->tailleY;  //Nombre de pixel en vertical

    cout << "Dimension du tableau : " << Dimension_X << " par " << Dimension_Y << endl<< endl;





/*  //Affichage du contenu du tableau
    for (unsigned int ligne = 0; ligne < Dimension_Y; ligne++){
        cout << ligne << "\t(";
        for (unsigned int col = 0; col < Dimension_X; col++) {
            if (tableauPixels[col + ligne*Dimension_X].pixelNoir) {
                cout <<  "1 ";
            }else {
                cout <<  "0 ";
            }
        }
        cout << ")" << endl;
    }
    */
}

void Lancer_LecteurImage(){

    LecteurImage* l = new LecteurImage("test_1.pbm.txt");
    lire_tableau_pixel(l);
    l = nullptr;

}

void Algorithme_Union(){
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
            if (!(colonne==0)) {//si il y a un pixel à gauche
                pixel_courant->propageCouleur(tableauPixels[ligne*Dimension_X + colonne-1]);
            }
            if (!(colonne==(Dimension_X-1))) {//si il y a un pixel à droite
                pixel_courant->propageCouleur(tableauPixels[ligne*Dimension_X + colonne+1]);
            }
        }
    }



}

int main()
{
    cout << "Alex est le mal dominant : " << sizeof(int) << endl;

    Lancer_LecteurImage();






    ///////////Debug
    cout << " # Main apres Lecteur \t Pixel : ("<< tableauPixels[1]->getX()<< "." << tableauPixels[1]->getY() << ")";
    cout << " = Ensemble : "<< "("<< tableauPixels[1]->getEnsemble()->getHead()->getX()<< "." << tableauPixels[1]->getEnsemble()->getHead()->getY() << ")" << endl;

    ///////////Debug

    Algorithme_Union();

    WriteFic *wf = new WriteFic(Dimension_Y, Dimension_X);

    wf->ajEnsembleTable(tableauPixels, Dimension_X*Dimension_Y);



    wf->writeThePPMFic();


    //wf->generate(5,5);

    return 0;
}

