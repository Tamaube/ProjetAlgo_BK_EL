#ifndef ENSEMBLE_H_INCLUDED
#define ENSEMBLE_H_INCLUDED

#include "Pixel.h"

class Ensemble {
private:
    Pixel _head;
    Pixel _tail;
    int size;

public:
    Ensemble(Pixel x);
};


#endif // ENSEMBLE_H_INCLUDED
