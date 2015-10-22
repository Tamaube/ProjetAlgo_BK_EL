#include "LecteurImage.h"


LecteurImage::LecteurImage(string nomImage)
{


    ifstream fichier(nomImage, ios::in);

    if(fichier){

        string entete;
        string dimension;

        getline(fichier, entete);


        getline(fichier, dimension);

        int separation = dimension.find(' ');


        std::string chaine_Taillex = dimension.substr(0, separation);
        std::string chaine_Tailley = dimension.substr(separation + 1, dimension.size() -1);

        tailleX = (unsigned int) atoi((char*)chaine_Taillex.c_str());
        tailleY = (unsigned int) atoi((char*)chaine_Tailley.c_str());

        cout << "taille de l'image :   " << tailleX << " x "<<tailleY << endl;


        tabPixels = (Pixel**) malloc(sizeof(Pixel*) * tailleX * tailleY );

        string ligne;
        unsigned int nbCharLu = 0;
        while (getline(fichier, ligne)) {
            for (unsigned int i = 0; i<ligne.size(); i++) {
                if (ligne[i] == '0') {
                    tabPixels[nbCharLu] = new Pixel(nbCharLu%tailleX, nbCharLu/tailleX, false);

                    nbCharLu++;
                }else if(ligne[i] == '1') {
                    tabPixels[nbCharLu] = new Pixel(nbCharLu%tailleX, nbCharLu/tailleX, true);
                    nbCharLu++;
                }
            }
        }
    fichier.close();

    } else {
        cerr << "Fonction LecteurImage : Impossible d'ouvrir le fichier " << nomImage << " !" << endl;
    }



}

LecteurImage::~LecteurImage()
{

}
