#include "Pixel.h"


Pixel::Pixel (int x, int y){
    this->_x = x;
    this->_y = y;
}
Pixel::Pixel (int x, int y, bool noir){
    this->_x = x;
    this->_y = y;
    this->pixelNoir = noir;
}
