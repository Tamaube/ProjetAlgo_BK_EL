#ifndef PIXEL_H_INCLUDED
#define PIXEL_H_INCLUDED

class Pixel {
private:
        Pixel* _head;
        Pixel* _next;
        int _x;
        int _y;

    public:
        Pixel(int x, int y);
        ~Pixel();

        int getX() { return _x;}
        int getY() { return _y;}


        Pixel* getHead() {return _head;}//Recuperer le representant dun ensemble
        Pixel* getNext() {return _next;}

        void setHead(Pixel* head){this->_head = head;}
        void setNext (Pixel* next){this->_next = next;}
};

#endif // PIXEL_H_INCLUDED
