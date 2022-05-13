#include <iostream>
#include "RejestrPojazdow.h"
#include "SamochodCiezarowy.h"
#include "SamochodOsobowy.h"

using namespace std;

int main() {

    RejestrPojazdow_ptr glowna(new RejestrPojazdow(5));
    Pojazd_ptr osobowka(new SamochodOsobowy("123" , 3));
    Pojazd_ptr ciezarowka(new SamochodCiezarowy("321" , 1000));
    glowna->dodajPojazd(osobowka);
    glowna->dodajPojazd(ciezarowka);
    cout<<glowna->toString();

    return EXIT_SUCCESS;
}