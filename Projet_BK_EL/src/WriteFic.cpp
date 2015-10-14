#include "WriteFic.h"

WriteFic::WriteFic(int nbrLig, int nbrCol)
{
    this->nbrCol = nbrCol;
    this->nbrLig = nbrLig;

    //Allocation de l espace
    this->tab2D_color = new char*[this->nbrLig * this->nbrCol];

    //initialisation de toute les cases du tab à noir
    for(int i = 0; i < this->nbrLig; ++i)
    {
        for(int j = 0; j < this->nbrCol; ++j)
        {
            this->tab2D_color[i * this->nbrCol + j] = "0 0 0";

        }
    }


}

/*
    ecrit le fichier ppm
    utilise la matrice tab2D_color pour le contenu du fichier
*/
void WriteFic::writeThePPMFic()
{
    ofstream fic("result.ppm", ios::out | ios::trunc);
    if(fic)
    {

        //Debut du fichier
        fic << "P3 " << endl << this->nbrCol << " " << this->nbrLig << endl;
        fic << "255" << endl;

        //Contenu du fichier
        for(int i = 0; i < this->nbrLig; i++)
        {
            for(int j = 0; j < this->nbrCol; j++)
            {
                if (strcmp(this->tab2D_color[i * this->nbrCol + j], "0 0 0"))
                {
                    fic <<  this->tab2D_color[i * this->nbrCol + j] << " ";
                } else {
                    cerr << "Erreur: le pixel " << i << " " << j << " = " <<" a deja ete colore" << endl;
                }
            }
            fic << endl;
        }

        fic.close();
    } else {
        cerr << "Erreur lors de la creation du fichier" << endl;
    }

}

/*
    Permet de stocker la couleur de chaque case dans une matrice tab2D_color
    tabEnsemble : le tableau contenant tous les ensemble de couleur
    tailleTab: taille du tableau tabEnsemble et du tabColor
    tabColor: tableau de couleur pour chaque ensemble
*/
void WriteFic::ajEnsembleTable(Ensemble **tabEnsemble, int tailleTab, char *tabColor[])
{

    for(int i = 0; i < tailleTab; i++)
    {
        Pixel * p = (**(tabEnsemble + i)).getHead();
        int size_ensemble = (**(tabEnsemble + i)).getSize();
        for(int j = 0; j < size_ensemble; j++)
        {

            this->tab2D_color[(p->getX() *  this->nbrCol) + p->getY()] = tabColor[i];
            p = p->getNext();
        }
    }

}
