#include "LecteurImage.h"


LecteurImage::LecteurImage(string nomImage)
{


    ifstream fichier(nomImage, ios::in);

    if(fichier){

        string entete;
        string dimension;

        getline(fichier, entete);

        cout << "Entete = " << entete << endl;

        getline(fichier, dimension);

        int separation = dimension.find(' ');


        std::string chaine_Taillex = dimension.substr(0, separation);
        std::string chaine_Tailley = dimension.substr(separation + 1, dimension.size() -1);
        cout << "\"" << chaine_Taillex  << "\" " << "\"" << chaine_Tailley  << "\""  << endl;
        //DEBUG

        tailleX = (unsigned int) atoi((char*)chaine_Taillex.c_str());
        tailleY = (unsigned int) atoi((char*)chaine_Tailley.c_str());

        cout << "taille de l'image :   " << tailleX << " x "<<tailleY << endl;
        cout << "taille du malloc  :   "<< tailleX*tailleY *sizeof(Pixel) << " octets "<< endl;


        tabPixels = (Pixel**) malloc(sizeof(Pixel*) * tailleX * tailleY );

        string ligne;
        unsigned int nbCharLu = 0;
        while (getline(fichier, ligne)) {
            for (unsigned int i = 0; i<ligne.size(); i++) {
                if (ligne[i] == '0') {
                    tabPixels[nbCharLu] = new Pixel(nbCharLu%tailleX, nbCharLu/tailleX, false);


                    //Debug

                    cout << " # Creation du pixel \t Pixel : ("<< tabPixels[nbCharLu]->getX()<< "." << tabPixels[nbCharLu]->getY() << ")";
                    cout << " = Ensemble : "<< "("<< tabPixels[nbCharLu]->getEnsemble()->getHead()->getX()<< "." << tabPixels[nbCharLu]->getEnsemble()->getHead()->getY() << ")" << endl;


                    //Debug
                    nbCharLu++;


                }else if(ligne[i] == '1') {
                    tabPixels[nbCharLu] = new Pixel(nbCharLu%tailleX, nbCharLu/tailleX, true);
                    nbCharLu++;
                }
            }
        }


    } else
        cerr << "Impossible d'ouvrir le fichier !" << endl;


    fichier.close();

    for (unsigned int i = 0; i< tailleX*tailleY; i++) {
        cout << i << "# Fin Lecteur \t Pixel : ("<< tabPixels[i]->getX()<< "." << tabPixels[i]->getY() << ")";
        cout << " = Ensemble : "<< "("<< tabPixels[i]->getEnsemble()->getHead()->getX()<< "." << tabPixels[i]->getEnsemble()->getHead()->getY() << ")" << endl;
    }
}

LecteurImage::~LecteurImage()
{

}


void LecteurImage::lireMetaDonnees() {

        string entete;
        string dimension;



        getline(fichier, entete);

        cout << "entete = " << entete << endl;

        getline(fichier, dimension);

        cout << dimension << endl;

        int separation = dimension.find(' ');

        cout << "séparation = " << separation << endl;


        std::string chaine_Taillex = dimension.substr(0, separation);
        std::string chaine_Tailley = dimension.substr(separation + 1, dimension.size() -1);
        cout << "\"" << chaine_Taillex  << "\" " << "\"" << chaine_Tailley  << "\""  << endl;
        //DEBUG

        tailleX = (unsigned int) atoi((char*)chaine_Taillex.c_str());
        tailleY = (unsigned int) atoi((char*)chaine_Tailley.c_str());

        cout << "taille de l'image :   " << tailleX << " x "<<tailleY << endl;
        cout << "taille du malloc  :   "<< tailleX*tailleY *sizeof(Pixel) << " octets "<< endl;

}
