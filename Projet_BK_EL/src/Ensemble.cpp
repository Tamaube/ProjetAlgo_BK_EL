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

    Pixel* AutrePixel;

    while (p)
    {
        //Debug
        unsigned int X_Moi = this->getHead()->getX();
        unsigned int Y_Moi = this->getHead()->getY();
        unsigned int X_Lui = p->getX();
        unsigned int Y_Lui = p->getY();
        //Debug

        p->setHead(this->_head);
        p->setEnsemble(this);
        AutrePixel = p;
        p = p->getNext();
    }

    this->_size += e->getSize();
    this->_tail->setNext(e->getHead());
    this->_tail = e->getTail();
    //free(e); //on détruit l'autre ensemble qui ne contient plus aucun pixel.

    //Debug
    Ensemble* Moi_Ensemble = this;
    Pixel* Moi_Representant = this->getHead();
    unsigned int Moi_Representant_X = this->getHead()->getX();
    unsigned int Moi_Representant_Y = this->getHead()->getY();


    Ensemble* AutrePixel_Ensemble = AutrePixel->getEnsemble();
    unsigned int AutrePixel_Representant_X = AutrePixel->getX();
    unsigned int AutrePixel_Representant_Y = AutrePixel->getY();





    //Debug




}
