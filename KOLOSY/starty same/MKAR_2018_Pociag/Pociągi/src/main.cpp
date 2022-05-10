#include <iostream>
#include "Pociag.h"
#include "Pasazerski.h"
#include "Towarowy.h"

using namespace std;

int main() {
    Wagon_ptr towarowy(new Towarowy(100,30));
    Wagon_ptr pasazerski (new Pasazerski(20, 60));
    Pasazerski_ptr pasazerski2(new Pasazerski(81, 40)); //nie powinien sie dodac yo
    Pociag_ptr pociag(new Pociag(200));
    pociag->dodajWagon(towarowy);
    pociag->dodajWagon(pasazerski);
    pociag->dodajWagon(pasazerski2);

    cout<<pociag->toString();

    return EXIT_SUCCESS;
}