#ifndef WRITEFIC_H_INCLUDED
#define WRITEFIC_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <ctime>
#include "Pixel.h"
#include "Ensemble.h"
#include <vector>

using namespace std;

class WriteFic {
private:
    char** tab2D_color;
    int nbrCol;
    int nbrLig;
    std::vector<Ensemble *> listEnsemble;
    std::vector<char *> listColor;
    std::vector<char *>::iterator itorColor;

public:
    WriteFic();
    WriteFic(int nbrLig, int nbrCol);
    ~WriteFic();
    char* getRandomColor();
    char* getCouleurEnsemble(Ensemble* e);

    void ajEnsembleTable(Pixel* tableauPixels, unsigned int tailleTab );
    void writeThePPMFic();

    void generate(int n, int m);

};

#endif // WRITEFIC_H_INCLUDED
