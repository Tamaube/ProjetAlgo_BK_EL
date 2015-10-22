#include <iostream>
#include "LecteurImage.h"
#include "testWriteFic.h"
#include "WriteFic.h"
#include "Pixel.h"
#include "Ensemble.h"


using namespace std;

void Algorithme_Union(Pixel** tableauPixels, unsigned int Dimension_X, unsigned int Dimension_Y){
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

int main()
{
    //========================== Interaction utilisateur =====================================
    string nomFic = "img_generate.ppm";
    char choixFicPerso;

    cout << "Voulez vous colorer un fichier en particulier ? (o/n)" << endl;
    cin >> choixFicPerso;
    while(choixFicPerso != 'o' && choixFicPerso != 'n')
    {
        cout << "La reponse doit etre 'o' ou 'n', voulez vous colorer un fichier en particulier ?" << endl;
        cin >> choixFicPerso;
    }


    WriteFic *wf = new WriteFic();


    if (choixFicPerso == 'o'){
        cout << "Veuillez entrer le chemin du fichier : ";
        cin >> nomFic;
        bool isPPM_file = false;
        int sizeNomFic;
        do {
            sizeNomFic = nomFic.size();
            if(sizeNomFic > 4)
            {
                isPPM_file = (nomFic[sizeNomFic - 4] == '.' && nomFic[sizeNomFic - 3] == 'p'
                              && nomFic[sizeNomFic - 2] == 'p' && nomFic[sizeNomFic - 1] == 'm')
                              || (nomFic[sizeNomFic - 4] == '.' && nomFic[sizeNomFic - 3] == 'p'
                              && nomFic[sizeNomFic - 2] == 'b' && nomFic[sizeNomFic - 1] == 'm');
            }
            if (!(sizeNomFic > 4 && isPPM_file))
            {
                cout << "Sasie incorrect ! (le fichier doit finir par '.ppm' ou '.pbm') Veuillez re - entrer le chemin du fichier : ";
                cin >> nomFic;
            }
        } while(!(sizeNomFic > 4 && isPPM_file));
    } else {
        srand(0);

        wf->generate();

    }


    //===================== Lancement de l'algorithme de coloriage =====================
    LecteurImage* l = new LecteurImage(nomFic);



    Pixel** tableauPixels = l->tabPixels;

    unsigned int nbrColonne = l->tailleX;  //Nombre de pixel en horizontal
    unsigned int nbrLigne = l->tailleY;  //Nombre de pixel en vertical

    free(l);

    Algorithme_Union(tableauPixels, nbrColonne, nbrLigne);

    wf->setNbrColFic(nbrColonne);
    wf->setNbrLigFic(nbrLigne);

    cout << "Ecriture du fichier en cours ..." << endl;
    wf->writeThePPMFic(tableauPixels, nbrColonne*nbrLigne);

    cout << "Fin de l'ecriture de fichier" << endl;


    return 0;
}

