#include "LecteurImage.h"


LecteurImage::LecteurImage(string nomImage) throw(string)
{


    ifstream fichier(nomImage, ios::in);

    if(fichier){

        string entete;
        string dimension;

         //On recupere le nombre magique
        getline(fichier, entete);

        //On recupere la taille du fichier
        getline(fichier, dimension);

        int separation = dimension.find(' ');
        std::string chaine_Taillex = dimension.substr(0, separation);
        std::string chaine_Tailley = dimension.substr(separation + 1, dimension.size() -1);

         //On stocke le nombre de colonnes dans tailleX et le nombre de lignes dans tailleY
        tailleX = (unsigned int) atoi((char*)chaine_Taillex.c_str());
        tailleY = (unsigned int) atoi((char*)chaine_Tailley.c_str());

        cout << "taille de l'image :   " << tailleY << " x "<<tailleX << endl;

        //On aloue l espace pour le tableau de pixels
        tabPixels = (Pixel**) malloc(sizeof(Pixel*) * tailleX * tailleY );

        //On verifie que le fichier a la bonne entete sinon on leve une exception
        if(! (entete.size() <= 3
              && entete[0] == 'P'
              && entete[1] == '1'))
        {
            throw string("Le nombre magique n est pas P1");
        }

        string ligne;
        unsigned int nbCharLu = 0;
        bool fichierCorrecte = true;
        while (getline(fichier, ligne)  && fichierCorrecte) {
            unsigned int i = 0;
            while ( i<ligne.size() && fichierCorrecte) {
                /*Le fichier ne doit pas avoir d autre caractere que des 0 ou des 1
                    ou des espaces, saut de ligne, fin de chaine
                    On stocke les 0 et 1 en tant que pixel dans tabPixels
                */
                if (ligne[i] == '0') {
                    tabPixels[nbCharLu] = new Pixel(nbCharLu%tailleX, nbCharLu/tailleX, false);

                    nbCharLu++;
                }else if(ligne[i] == '1') {
                    tabPixels[nbCharLu] = new Pixel(nbCharLu%tailleX, nbCharLu/tailleX, true);
                    nbCharLu++;
                } else {
                    fichierCorrecte  = (ligne[i] == '\0' || ligne[i] == ' ' || ligne[i]== '\n');
                }
                i++;
            }
        }

        //On verirfie que le fichier a bien le nombre attendu de pixel
        fichierCorrecte = (nbCharLu == tailleX * tailleY);

        //Si le fichier est incorrecte on leve une exception
        if(!fichierCorrecte)
        {
            throw string("Fichier incorrecte");
        }
        fichier.close();
    } else {
        throw string("Impossible d'ouvrir le fichier " + nomImage + " !");
    }



}

LecteurImage::~LecteurImage()
{

}
