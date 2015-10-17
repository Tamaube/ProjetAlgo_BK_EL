#include <iostream>
#include "LecteurImage.h"
#include "testWriteFic.h"
#include "WriteFic.h"


using namespace std;

void test_LecteurImage(){

    LecteurImage* l = new LecteurImage();

}
int main()
{
//    testEcriture();

    cout << "Alex est le mal dominant" << endl;

//    test_LecteurImage();
    WriteFic *wf = new WriteFic();
    wf->generate(5,5);
    return 0;
}

