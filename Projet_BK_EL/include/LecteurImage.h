#ifndef LECTEURIMAGE_H
#define LECTEURIMAGE_H


class LecteurImage
{



    public:
        LecteurImage();
        ~LecteurImage();
    protected:
    private:
        unsigned int tailleX;
        unsigned int tailleY;
        Pixel **tabPixels;
        ifstream fichier;
};

#endif // LECTEURIMAGE_H
