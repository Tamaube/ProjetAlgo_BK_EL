#ifndef PIXEL_H_INCLUDED
#define PIXEL_H_INCLUDED
#include "Ensemble.h"
class Ensemble;

class Pixel {
private:
        Ensemble* _ensemble;
        Pixel* _head;
        Pixel* _next;
        int _x;
        int _y;

    public:
        bool pixelNoir;

        Pixel(int x, int y);
        Pixel(int x, int y, bool noir);

        void propageCouleur(Pixel* pixel_Adjacent);
        bool dans_Meme_Ensemble(Pixel* autre_Pixel);
        //~Pixel();

        int getX() { return _x;}
        int getY() { return _y;}


        Pixel* getHead() {return _head;}//Recuperer le representant dun ensemble, findSet
        Pixel* getNext() {return _next;}
        Ensemble* getEnsemble() {return _ensemble;}

        void setHead(Pixel* head){this->_head = head;}
        void setNext (Pixel* next){this->_next = next;}
        void setEnsemble (Ensemble* e){this->_ensemble = e;}
};

#endif // PIXEL_H_INCLUDED
