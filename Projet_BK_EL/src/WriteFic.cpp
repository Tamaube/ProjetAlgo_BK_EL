#include "WriteFic.h"

char* WriteFic::getRandomColor() {


    //cout << "==== Début de la fonction ajEnsembleTable" << endl;

    unsigned char c1 = rand()%256;
    unsigned char c2 = rand()%256;
    unsigned char c3 = rand()%256;

    string result =  "           ";


    result[0] = '0' + c1/100 ;
    result[1] = '0' + (c1/10)%10;
    result[2] = '0' + c1%10;


    result[4] = '0' + c2/100;
    result[5] = '0' + (c2/10)%10;
    result[6] = '0' + c2%10;


    result[8] = '0' + c3/100;
    result[9] = '0' + (c3/10)%10;
    result[10] = '0' + c3%10;

    cout << result << " ";

    char * cstr = new char [result.length()+1];
    std::strcpy (cstr, result.c_str());

    return cstr;
}

char* WriteFic::getCouleurPixel(void* ptr) {

    bool trouve = false;
    std::vector<unsigned long int>::iterator itor;
    int i = 0;
    for (itor = listPtrEnsemble.begin (); itor != listPtrEnsemble.end (); ++itor) {
        if (*itor == (unsigned long int) ptr) {
            trouve = true;
        }else if (!trouve) {
            i++;
        }
    }
    if (!trouve) {

        cout << "New " ;
        listPtrEnsemble.push_back((unsigned long int) ptr);
        listColor.push_back(getRandomColor());
    }

    cout << i << " " ;
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
void WriteFic::ajEnsembleTable(Pixel** tableauPixels, unsigned int tailleTab )
{

    cout << endl << "== Debut de la fonction ajEnsembleTable" << endl;

    cout << endl << "Test du tableauPixels : " << endl;

    for (int i = 0; i < 10; i++){

        cout << " coordonees :  \t" << tableauPixels[i]->getX() << "." << tableauPixels[i]->getY() << endl;
        if (tableauPixels[i]->pixelNoir) {
            cout << " pixel noir. " << endl;
        } else {
            cout << " pointeur tete :\t" << (unsigned long int) tableauPixels[i]->getHead() << endl;
        }

    }

    cout << endl << " Pixel du premier ensemble : " << endl;
    int j = 0;
    while (tableauPixels[j]->pixelNoir)
        j++;

    Ensemble * ens = tableauPixels[j]->getEnsemble();

    cout << "Ensemble :   taille = " << ens->getSize() << "  tete = " << ens->getHead() ;

    Pixel* pixelCourant = ens->getHead();

    while (pixelCourant != nullptr) {
        cout << " (" << pixelCourant->getX() << ", " << pixelCourant->getY() << ")";
        pixelCourant = pixelCourant->getNext();
    }


    tab2D_color = (char**) malloc(sizeof(char*)*tailleTab);
    for(unsigned int i = 0; i < tailleTab; i++)
    {

        //cout << getCouleurEnsemble(tableauPixels[i].getEnsemble()) << " ";
        if (!tableauPixels[i]->pixelNoir){
            cout << (unsigned long int) tableauPixels[i]->getHead();
            tab2D_color[i] = getCouleurPixel(tableauPixels[i]->getHead());

        }

        /*Pixel * p = (**(tabEnsemble + i)).getHead();
        int size_ensemble = (**(tabEnsemble + i)).getSize();
        for(int j = 0; j < size_ensemble; j++)
        {

            this->tab2D_color[(p->getX() *  this->nbrCol) + p->getY()] = tabColor[i];
            p = p->getNext();
        }*/
    }

    cout << endl <<"Nombre d'Ensemble trouvé : " << listPtrEnsemble.size() << endl;
    cout << "Les différentes couleurs utilise : " << endl;
    for (int i = 0; i < listColor.size(); i++)
        cout << listColor[i] << "; ";

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
