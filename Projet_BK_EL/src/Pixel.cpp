#include "Pixel.h"


Pixel::Pixel (int x, int y){
    this->_x = x;
    this->_y = y;
    this->pixelNoir = false;
    this->_ensemble = new Ensemble(this);
}
Pixel::Pixel (int x, int y, bool noir){
    this->_x = x;
    this->_y = y;
    this->pixelNoir = noir;
    this->_ensemble = nullptr;
}
bool Pixel::dans_Meme_Ensemble(Pixel* autre_Pixel){

    return getEnsemble() == autre_Pixel->getEnsemble();

}

void Pixel::propageCouleur(Pixel* pixel_Adjacent){

    if(!this->pixelNoir && !pixel_Adjacent->pixelNoir){ // On vérifie que nous n'avons pas à faire avec un pixel noir (oui, il y a discrimination...)
        if (!dans_Meme_Ensemble(pixel_Adjacent)){
            Ensemble* monEnsemble = this->getEnsemble();
            Ensemble* autreEnsemble = pixel_Adjacent->getEnsemble();

            monEnsemble->addEnsemble_inTail(autreEnsemble);
        }
    }


}
