#ifndef ENSEMBLE_H_INCLUDED
#define ENSEMBLE_H_INCLUDED

#include "Pixel.h"
#include <iostream>

using namespace std;

//Ensemble de pixel
class Pixel;

class Ensemble {
private:
    Pixel* _head;
    Pixel* _tail;
    int _size;

public:
    //Make set
    Ensemble(Pixel* x);
    ~Ensemble();

    Pixel* getHead() { return this->_head;}//Recuperer le representant d'un ensemble
    Pixel* getTail() { return this->_tail;}//Recuperer la tail d'un ensemble

    int getSize(){ return this->_size;}

    //Ajoute un ensemble à la fin, e est le plus petit ensemble
    void addEnsemble_inTail(Ensemble* e)throw(string);


};


#endif // ENSEMBLE_H_INCLUDED
