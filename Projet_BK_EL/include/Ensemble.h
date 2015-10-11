#ifndef ENSEMBLE_H_INCLUDED
#define ENSEMBLE_H_INCLUDED

#include "Pixel.h"

class Ensemble {
private:
    Pixel * _head;
    Pixel * _tail;
    int _size;

public:
    //Make set
    Ensemble(Pixel* x);
    ~Ensemble();

    Pixel* getHead() { return this->_head;}//Recuperer le representant d'un ensemble
    Pixel* getTail() { return this->_tail;}

    int getSize(){ return this->_size;}

    //Ajoute un pixel à la fin de l'ensemble
    void addPixel(Pixel* p);

    //Ajoute un ensemble à la fin, e est le plus petit ensemble
    void addEnsemble_inTail(Ensemble* e);


};


#endif // ENSEMBLE_H_INCLUDED
