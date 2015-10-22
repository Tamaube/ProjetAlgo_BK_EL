#include "Ensemble.h"
#include <cstdlib>

Ensemble::Ensemble(Pixel* x) {
    this->_size = 1;
    this->_head = x;
    this->_tail = x;

}

/*Ajoute un ensemble à la fin
  e: le plus petit ensemble
*/
void Ensemble::addEnsemble_inTail(Ensemble* e)throw(string){
    if(e->getHead() == this->_head)
    {
        throw string("Erreur lors de l'ajout de l'ensemble les representants sont les memes");
    }
    Pixel* p = e->getHead();
    while (p)
    {
        p->setHead(this->_head);
        p->setEnsemble(this);
        p = p->getNext();
    }

    this->_size += e->getSize();
    this->_tail->setNext(e->getHead());
    this->_tail = e->getTail();
    free(e); //on détruit l'autre ensemble qui ne contient plus aucun pixel.
}
