#include "WriteFic.h"

char* WriteFic::getRandomColor() {
    unsigned char c1 = rand()%256;
    unsigned char c2 = rand()%256;
    unsigned char c3 = rand()%256;

    char* result = new char[10];
    result =  "           ";

    result[0] = c1/100;
    result[1] = (c1/10)%10;
    result[2] = c1%10;


    result[4] = c2/100;
    result[5] = (c2/10)%10;
    result[6] = c2%10;


    result[8] = c3/100;
    result[9] = (c3/10)%10;
    result[10] = c3%10;

    return result;
}

char* WriteFic::getCouleurEnsemble(Ensemble* e) {

    bool trouve = false;
    std::vector<Ensemble*>::iterator itor;
    int i = 0;
    for (itor = listEnsemble.begin (); itor != listEnsemble.end (); ++itor) {
        if (*itor == e) {
            trouve = true;
        }else {
            i++;
        }
    }
    if (!trouve) {
        listEnsemble.push_back(e);
        listColor.push_back(getRandomColor());
    }

    return listColor[i];

}

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

WriteFic::WriteFic()
{
    srand (time(0));
    itorColor = listColor.begin();
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
void WriteFic::ajEnsembleTable(Pixel* tableauPixels, unsigned int tailleTab )
{

    tab2D_color = (char**) malloc(sizeof(char*)*tailleTab);
    for(unsigned int i = 0; i < tailleTab; i++)
    {
        tab2D_color[i] = getCouleurEnsemble(tableauPixels[i].getEnsemble());

        /*Pixel * p = (**(tabEnsemble + i)).getHead();
        int size_ensemble = (**(tabEnsemble + i)).getSize();
        for(int j = 0; j < size_ensemble; j++)
        {

            this->tab2D_color[(p->getX() *  this->nbrCol) + p->getY()] = tabColor[i];
            p = p->getNext();
        }*/
    }

}


void WriteFic::generate (int n, int m)
{
    ofstream fic("img_generate.ppm", ios::out | ios::trunc);
    if(fic)
    {
         //Debut du fichier
        fic << "P1 " << endl << m << " " << n << endl;
        fic << "255" << endl;

        //Contenu du fichier
        for(int i = 0; i < n; ++i)
        {
            for(int j=0; j < m; ++j){

                int v = rand() %2;
                fic << v << " ";

            }
            fic << endl;
        }

        fic.close();
    } else {
        cerr << "Erreur lors de la creation du fichier" << endl;
    }

}
