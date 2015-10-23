
#include "comparaisonGenerate.h"

/*
Permet de voir les différents cout en temps avec une image de plus en plus grande (question 13)

*/
void comparaison()
{
    for(int i = 1; i <= 20; ++i)
    {
        WriteFic *wf = new WriteFic();
        wf->generate(i * 100, i *100);

        auto start = std::chrono::high_resolution_clock::now();
        LecteurImage* l = new LecteurImage("img_generate.pbm");

        Pixel** tableauPixels = l->tabPixels;

        unsigned int nbrColonne = l->tailleX;  //Nombre de pixel en horizontal
        unsigned int nbrLigne = l->tailleY;  //Nombre de pixel en vertical

        free(l);

        algo_union(tableauPixels, nbrColonne, nbrLigne);

        wf->setNbrColFic(nbrColonne);
        wf->setNbrLigFic(nbrLigne);

        wf->writeThePPMFic(tableauPixels, nbrColonne*nbrLigne);

       auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;

        std::cout << "Taille: " << i * i * 10000 <<" Temps pour colorer " << diff.count() << " s\n";

    }
}
