#include <iostream>
#include "Glowna.h"
#include "Pochodna1.h"
#include "Pochodna2.h"

using namespace std;

int main() {

    Glowna_ptr glowna(new Glowna( ));
    Abstrakcyjna_ptr pochodna1(new Pochodna1( ));
    Abstrakcyjna_ptr pochodna2(new Pochodna2( ));
    glowna->dodaj(pochodna1);
    glowna->dodaj(pochodna2);
    cout<<glowna->toString();

    return EXIT_SUCCESS;

}