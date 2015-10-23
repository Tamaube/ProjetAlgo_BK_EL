#include "WriteFic.h"

char* WriteFic::getRandomColor() {

    //Generation de trois couleurs aleatoires
    unsigned char c1 = rand()%256;
    unsigned char c2 = rand()%256;
    unsigned char c3 = rand()%256;

    //On stocke les trois couleurs dans une string
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


/*
    Permet d'avoir la couleur d'un ensemble
*/
char* WriteFic::getCouleurPixel(void* ptr) {

    bool trouve = false;
    std::vector<unsigned long int>::iterator itor = listPtrEnsemble.begin ();
    int i = 0;

    //Tant que le representant na pas ete trouve dans listPtrEnsemble on continu de le chercher
    while (itor != listPtrEnsemble.end () && !trouve) {

        if (listPtrEnsemble[i] == (unsigned long int) ptr) {
            trouve = true;
        }else {
            i++;
        }
        ++itor;
    }
    /*Si on ne le trouve pas cest que cest un nouvel ensemble pas encore stocké dans listPtrEnsemble
        et on lui ajoute une couleur corespondante dans listColor (au meme indice que dans listPtrEnsemble)
    */
    if (!trouve) {
        listPtrEnsemble.push_back((unsigned long int) ptr);
        listColor.push_back(getRandomColor());
    }

    //On renvoi la couleur correspondant a lensemble
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
                if (!tableauPixels[i * this->nbrColFic + j]->pixelNoir){ //On verifie si le pixel est noir
                    //On va chercher la couleur de lensemble
                    color = getCouleurPixel(tableauPixels[i * this->nbrColFic + j]->getHead());
                }
                fic <<  color << " "; // on ecrit la couleur
            }
            fic << endl;
        }
        fic.close();
    } else {
        throw string("Fonction writeThePPMFic : Erreur lors de la creation du fichier");
    }

}


void WriteFic::generate (int n, int m) throw(string)
{

    if(n <= 0 || m <= 0){
       throw string("la taille donnee en parametre de generate est incorrect");
    }
    ofstream fic("img_generate.pbm", ios::out | ios::trunc);
    if(fic)
    {
         //Debut du fichier
        fic << "P1 " << endl << m << " " << n << endl;

        //Contenu du fichier
        for(int i = 0; i < n; ++i)
        {
            for(int j=0; j < m; ++j){

                int v = rand() %3;
                if (v == 1){
                    fic << 1 << " ";
                } else {
                    fic << 0 << " ";
                }

            }
            fic << endl;
        }

        fic.close();
    } else {
        throw string("Fonction generate : Erreur lors de la creation du fichier");
    }

}
