#ifndef WRITEFIC_H_INCLUDED
#define WRITEFIC_H_INCLUDED

#include <fstream>
#include <iostream>
#include <string.h>
#include "Pixel.h"
#include "Ensemble.h"

using namespace std;

class WriteFic {
private:
    string **tab2D_color;
    int nbrCol;
    int nbrLig;

public:
    WriteFic();
    ~WriteFic();

    void ajEnsembleTable(Ensemble *tabEnsemble, int tailleTab, string *tabColor);
    void writeThePPMFic();

    void generate();
};

#endif // WRITEFIC_H_INCLUDED
