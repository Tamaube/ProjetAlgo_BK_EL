#ifndef WRITEFIC_H_INCLUDED
#define WRITEFIC_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "Pixel.h"
#include "Ensemble.h"

/*  On utilise une liste sous forme de vecteur pour stocker la couleur attribu�e � chaque ensemble
 *  Car il est difficile de deviner la taiile n�cessaire pour stocker ces informations
 */
#include <vector>


using namespace std;


class WriteFic {
private:
    int nbrColFic;
    int nbrLigFic;
    std::vector<unsigned long int> listPtrEnsemble;
    std::vector<char *> listColor;
    std::vector<char *>::iterator itorColor;
public:
    char** tab2D_color;
    WriteFic();
    WriteFic(int nbrLig, int nbrCol);
    ~WriteFic();

    void setNbrColFic(int nbrCol){this->nbrColFic = nbrCol;}
    void setNbrLigFic(int nbrLig){this->nbrLigFic = nbrLig;}
    char* getRandomColor();
    char* getCouleurPixel(void* ptr);

    void writeThePPMFic(Pixel** tableauPixels, unsigned int tailleTab)throw(string);

    void generate(int n, int m)throw(string);

};

#endif // WRITEFIC_H_INCLUDED
