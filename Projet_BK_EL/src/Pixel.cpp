#include "Pixel.h"

/* Ici le MAKESET() */
Pixel::Pixel (int x, int y, bool noir){
    this->_x = x;
    this->_y = y;
    this->pixelNoir = noir;
    this->setNext(nullptr);
    this->setHead(this);
    if (noir)
        this->_ensemble = nullptr;
    else
        this->_ensemble = new Ensemble(this);

}
/* SURCHARGE du constructeur pour implicitement d�clarer que le pixel n'est pas noir */
Pixel::Pixel (int x, int y){
    this->_x = x;
    this->_y = y;
    this->pixelNoir = false;
    this->_ensemble = new Ensemble(this);
    this->setNext(nullptr);
    this->setHead(this);
}

Pixel* Pixel:: getHead() {
    return getEnsemble()->getHead();

}//Recuperer le representant dun ensemble, findSet


/*  Cette fonction revoie vrai si l'objet pixel sur lequel est appel� cette fonction
 *  est dans le meme ensemble que celui en param�tre
 */
bool Pixel::dans_Meme_Ensemble(Pixel* autre_Pixel){

    Pixel* Mon_representant = getEnsemble()->getHead();

    Pixel* Son_representant = autre_Pixel->getEnsemble()->getHead();
    return Mon_representant == Son_representant;

}


/*  Cette fonction essaye d'ajouter l'ensemble du pixel pass� en param�tre dans son ensemble
 *  si les conditions s'y pr�tent :
 *      - Les deux pixels ne sont pas encore dans le m�me ensemble.
 *      - Aucun des deux pixels n'est un pixel noir.
 */

void Pixel::propageCouleur(Pixel* pixel_Adjacent){

    if(!this->pixelNoir && !pixel_Adjacent->pixelNoir){ // On v�rifie que nous n'avons pas � faire avec un pixel noir (oui, il y a discrimination...)
        if (!dans_Meme_Ensemble(pixel_Adjacent) ){



            Ensemble* monEnsemble = this->getEnsemble();
            Ensemble* autreEnsemble = pixel_Adjacent->getEnsemble();

            if (monEnsemble->getSize() > autreEnsemble->getSize()){
                monEnsemble->addEnsemble_inTail(autreEnsemble);
            } else {
                autreEnsemble->addEnsemble_inTail(monEnsemble);
            }


        }
    }


}
