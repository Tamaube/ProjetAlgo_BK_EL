#include <iostream>
#include "LecteurImage.h"
#include "testWriteFic.h"
#include "WriteFic.h"
#include "Pixel.h"
#include "Ensemble.h"
#include "union.h"


using namespace std;



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
        wf->generate();

    }


    //===================== Lancement de l'algorithme de coloriage =====================
    try{
        LecteurImage* l = new LecteurImage(nomFic);

        Pixel** tableauPixels = l->tabPixels;

        unsigned int nbrColonne = l->tailleX;  //Nombre de pixel en horizontal
        unsigned int nbrLigne = l->tailleY;  //Nombre de pixel en vertical

        free(l);

        algo_union(tableauPixels, nbrColonne, nbrLigne);

        wf->setNbrColFic(nbrColonne);
        wf->setNbrLigFic(nbrLigne);

        cout << "Ecriture du fichier en cours ..." << endl;
        wf->writeThePPMFic(tableauPixels, nbrColonne*nbrLigne);

        cout << "Fin de l'ecriture de fichier" << endl;
    } catch(string message)
    {
        cerr << message << endl;
    }
    return 0;
}

