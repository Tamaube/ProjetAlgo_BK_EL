#include "WriteFic.h"


void writeThePPMFic(){
    ofstream fic("result.ppm", ios::out | ios::trunc);

    if(fic)
    {
        //Debut du fichier
        fic << "P3 " << endl << this.nbrCol << " " << this.nbrLig << endl;
        fic << "255" << endl;

        //Contenu du fichier
        for(int i = 0; i < this.nbrLig; i++)
        {
            for(int j = 0; j < this.nbrCol; j++)
            {
                fic << this.tab2D_color[i][j] << " ";
            }
            fic << endl;
        }

        fic.close();
    } else {
        cerr << "Erreur lors de la creation du fichier" << endl;
    }

}

void ajEnsembleTable(Ensemble *tabEnsemble, int tailleTab, unsigned char **tabColor)
{
    for(int i = 0; i < tailleTab; i++)
    {
        Pixel p = *(tabEnsemble + i).getHead();
        for(int j = 0; j < *(tabEnsemble + i).getSize(); j++)
        {
            this.tab2D_color[p.getX()][p.getY()] = {tabColor[i][0], tabColor[i][1], tabColor[i][2]};
            p = p.getNext();
        }
    }
}
