#include "Ensemble.h"
#include <cstdlib>

Ensemble::Ensemble(Pixel* x) {
    this->_size = 1;
    this->_head = x;
    this->_tail = x;
}

//On ajoute un pixel a la fin
void Ensemble::addPixel(Pixel* p) {
    (this->_size)++;
    (this->_tail)->setNext(p);
    p->setHead(this->_head);
    this->_tail = p;
}

/*Ajoute un ensemble à la fin
  e: le plus petit ensemble
*/
void Ensemble::addEnsemble_inTail(Ensemble* e){
    Pixel* p = e->getHead();

    for(int i = 0; i < e->getSize(); ++i)
    {
        p->setHead(this->_head);
        p = p->getNext();
    }

    this->_size += e->getSize();
    this->_tail->setNext(e->getHead());
    this->_tail = e->getTail();
    free(e); //on détruit l'autre ensemble qui ne contient plus aucun pixel.
}
