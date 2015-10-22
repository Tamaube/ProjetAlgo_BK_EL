#include "WriteFic.h"

char* WriteFic::getRandomColor() {

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



    char * cstr = new char [result.length()+1];
    std::strcpy (cstr, result.c_str());

    return cstr;
}

char* WriteFic::getCouleurPixel(void* ptr) {

    bool trouve = false;
    std::vector<unsigned long int>::iterator itor = listPtrEnsemble.begin ();
    int i = 0;
    while (itor != listPtrEnsemble.end () && !trouve) {

        if (listPtrEnsemble[i] == (unsigned long int) ptr) {
            trouve = true;
        }else {
            i++;
        }
        ++itor;
    }
    if (!trouve) {
        listPtrEnsemble.push_back((unsigned long int) ptr);
        listColor.push_back(getRandomColor());
    }

    return listColor[i];

}

WriteFic::WriteFic(int nbrLig, int nbrCol)
{
    srand (time(0));
    itorColor = listColor.begin();

    this->nbrColFic = nbrCol;
    this->nbrLigFic = nbrLig;
}

WriteFic::WriteFic(){
    srand (time(0));
    itorColor = listColor.begin();
}

/*
    ecrit le fichier ppm
    utilise la matrice tab2D_color pour le contenu du fichier
*/
void WriteFic::writeThePPMFic(Pixel** tableauPixels, unsigned int tailleTab)throw(string)
{
    ofstream fic("result.ppm", ios::out | ios::trunc);


    if(fic)
    {

        //Debut du fichier
        fic << "P3 " << endl << this->nbrColFic << " " << this->nbrLigFic << endl;
        fic << "255" << endl;

        //Contenu du fichier
        for(int i = 0; i < this->nbrLigFic; i++)
        {
            for(int j = 0; j < this->nbrColFic; j++)
            {
                string color = "0 0 0";
                if (!tableauPixels[i * this->nbrColFic + j]->pixelNoir){
                    color = getCouleurPixel(tableauPixels[i * this->nbrColFic + j]->getHead());
                }
                fic <<  color << " ";
            }
            fic << endl;
        }
        fic.close();
    } else {
        throw string("Fonction writeThePPMFic : Erreur lors de la creation du fichier");
    }

}


void WriteFic::generate () throw(string)
{
    int n = rand()%MAX_TAILLE_LIGNE_COLONNE_FIC_GENERATE;
    int m  = rand()%MAX_TAILLE_LIGNE_COLONNE_FIC_GENERATE;

    ofstream fic("img_generate.ppm", ios::out | ios::trunc);
    if(fic)
    {
         //Debut du fichier
        fic << "P1 " << endl << m << " " << n << endl;

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
        throw string("Fonction generate : Erreur lors de la creation du fichier");
    }

}
