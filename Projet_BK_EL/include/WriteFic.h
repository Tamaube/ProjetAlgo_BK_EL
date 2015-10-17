#ifndef WRITEFIC_H_INCLUDED
#define WRITEFIC_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <string.h>
#include "Pixel.h"
#include "Ensemble.h"

using namespace std;

class WriteFic {
private:
    char** tab2D_color;
    int nbrCol;
    int nbrLig;

public:
    WriteFic(int nbrLig, int nbrCol);
    ~WriteFic();

    void ajEnsembleTable(Ensemble **tabEnsemble, int tailleTab, char *tabColor[]);
    void writeThePPMFic();

    void generate();
};

#endif // WRITEFIC_H_INCLUDED
