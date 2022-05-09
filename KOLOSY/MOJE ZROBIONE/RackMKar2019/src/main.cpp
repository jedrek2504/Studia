//GITUWA SKONCZONE RACK

#include <iostream>
#include "Rack.h"
#include "Macierz.h"
#include "Serwer.h"

using namespace std;

int main() {

    RackPtr r(new Rack(500));
    MacierzPtr m1(new Macierz("M1", 10, 10));
    MacierzPtr m2(new Macierz("M2", 20, 10));
    SerwerPtr s1(new Serwer("S1", 100));
    SerwerPtr s2(new Serwer("S2", 200));

    r->dodajPolke(m1);
    r->dodajPolke(s1);
    r->dodajPolke(m2);
    r->dodajPolke(s2); //powinno zwrocic false i nie dodac


    cout<<r->toString();

    r->usunPolke(m2);

    cout<<r->toString();

    return EXIT_SUCCESS;
}