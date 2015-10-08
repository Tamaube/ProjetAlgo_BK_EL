#ifndef WRITEFIC_H_INCLUDED
#define WRITEFIC_H_INCLUDED

#include <fstream>
#include "Pixel.h"
#include "Ensemble.h"

class WriteFic {
private:
    unsigned char **tab2D_color;
    int nbrCol;
    int nbrLig;

public:
    WriteFic();
    ~WriteFic();

    void ajEnsembleTable(Ensemble *tabEnsemble, int tailleTab, unsigned char **tabColor);
    void writeThePPMFic();

    void generate();
};

#endif // WRITEFIC_H_INCLUDED
