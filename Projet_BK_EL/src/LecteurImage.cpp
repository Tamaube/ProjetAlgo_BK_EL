#include "LecteurImage.h"

LecteurImage::LecteurImage()
{

    unsigned char bit;
    ifstream myfile ("vigne");
    if (myfile.is_open()) {

        // on skipe la première ligne


        while ( getline (myfile,bit) ){
            cout << bit << ' ';
        }
        myfile.close();
    }

    else cout << "Unable to open file";


    ifstream fichier("vigne", ios::in);

    if(fichier){
        int entier1, entier2;
        string chaine1, chaine2;

        fichier >> entier1 >> entier2 >> chaine1 >> chaine2;  /*on lit jusqu'à l'espace et on stocke ce qui est lu dans la variable indiquée */

        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;

    return 0;
}

LecteurImage::~LecteurImage()
{
    //dtor
}
