#include <iostream>
#include "Regal.h"
#include "Czasopismo.h"
#include "Ksiazka.h"

using namespace std;

int main() {
    Regal_ptr regal(new Regal(4));
    Element_ptr ksiazka2(new Ksiazka("Tren2", "Jan Kochanowski", 2));
    Element_ptr czasopismo1(new Czasopismo("Deadpool", 1));
    regal->odloz(ksiazka2);
    regal->odloz(czasopismo1);
    cout<<regal->toString();

    return EXIT_SUCCESS;
}