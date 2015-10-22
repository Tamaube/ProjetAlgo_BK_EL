#include "testWriteFic.h"

/*
   Permet de tester la fonction writeThePPMFic de la classe WriteFic
   Il faut ensuite verifier le fichier result.pbm qui doit contenir 4 pixel repartie sur 2 lignes
   chaque pixel doit etre d une couleur differente
*/
void testEcriture()
{
    cout << "testEcriture" << endl;
    Pixel *tabPixel[4] = {new Pixel(0,0) ,new Pixel(1,0),new Pixel(0,1), new Pixel(1,1)};

    WriteFic * wf;
    wf = new WriteFic(2, 2);

    wf->writeThePPMFic(tabPixel, 4);

}

/*
    Permet de tester la fonction generate de WriteFic
*/
void testGenerate() throw(string)
{
    //Lance le generate
    WriteFic *wf = new WriteFic();
    wf->generate();

    /*
    Ensuite on lit le fichier pour être sur qu il est au bon format
    */
    ifstream fichier("img_generate.ppm", ios::in);

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
        unsigned int tailleX = (unsigned int) atoi((char*)chaine_Taillex.c_str());
        unsigned int tailleY = (unsigned int) atoi((char*)chaine_Tailley.c_str());

        //On verifie que le fichier a la bonne entete
        bool fichierCorrecte = false;
        if(entete.size() == 3
           && entete[0] == 'P'
           && entete[1] == '1')
        {
            fichierCorrecte = true;
            string ligne;
            unsigned int nbCharLu = 0;

            while (getline(fichier, ligne) && fichierCorrecte) {
                unsigned int i = 0;
                while ( i < ligne.size() && fichierCorrecte) {
                    //Le fichier ne doit pas avoir d autre caractere que des 0 ou des 1 ou des espaces, saut de ligne, fin de chaine
                    if (ligne[i] == '0' && ligne[i] == '1') {
                        nbCharLu++;
                    } else {
                        fichierCorrecte  = (ligne[i] == '\0' || ligne[i] == ' ' || ligne[i]== '\n');
                    }
                    i++;
                }
            }
            //On verirfie que le fichier a bien le nombre attendu de pixel
            fichierCorrecte = (nbCharLu == tailleX * tailleY);
        }
        fichier.close();

        if(fichierCorrecte)
        {
            cout << "Test generate fichier correcte" << endl;
        } else {
            cout << "Test generate fichier incorrecte" << endl;
        }
    } else {
        throw ("Impossible d'ouvrir le fichier  !");
    }

}

