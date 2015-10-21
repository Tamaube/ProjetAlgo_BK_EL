#include "Pixel.h"


Pixel::Pixel (int x, int y){
    this->_x = x;
    this->_y = y;
    this->pixelNoir = false;
    this->_ensemble = new Ensemble(this);
    this->setNext(nullptr);
    this->setHead(this);
}
Pixel::Pixel (int x, int y, bool noir){
    this->_x = x;
    this->_y = y;
    this->pixelNoir = noir;
    this->setNext(nullptr);
    this->setHead(nullptr);
    if (noir)
        this->_ensemble = nullptr;
    else
        this->_ensemble = new Ensemble(this);

}

Pixel* Pixel:: getHead() {
    return getEnsemble()->getHead();

}//Recuperer le representant dun ensemble, findSet

bool Pixel::dans_Meme_Ensemble(Pixel* autre_Pixel){

    Pixel* Mon_representant = getEnsemble()->getHead();

    Pixel* Son_representant = autre_Pixel->getEnsemble()->getHead();






    if ( Mon_representant == Son_representant)
        return Mon_representant == Son_representant;
    else
        return Mon_representant == Son_representant;

}

void Pixel::propageCouleur(Pixel* pixel_Adjacent){

    if(!this->pixelNoir && !pixel_Adjacent->pixelNoir){ // On vérifie que nous n'avons pas à faire avec un pixel noir (oui, il y a discrimination...)
        bool meme_ensemble = dans_Meme_Ensemble(pixel_Adjacent);
        if (!meme_ensemble ){



            Ensemble* monEnsemble = this->getEnsemble();
            Ensemble* autreEnsemble = pixel_Adjacent->getEnsemble();

            monEnsemble->addEnsemble_inTail(autreEnsemble);


        }
    }


}
