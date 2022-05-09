#include <iostream>
#include "Statek.hpp"
#include "Luzny.hpp"
#include "Paletowy.hpp"


int main() {
    Statek ship(2000000);
    ladunekPtr paleta1(new Paletowy("paleta1", 100, 20));
    ladunekPtr luzny2(new Luzny("luzny1", 100));
    ship.dodajLadunek(paleta1);
    ship.dodajLadunek(luzny2);
    std::cout << ship.toString();
    return EXIT_SUCCESS;
}