//SKONCZONE STATEK KARBO 2020

#include <iostream>
#include "Statek.h"
#include "Paletowy.h"
#include "Luzny.h"

using namespace std;

int main() {
    Statek_ptr s(new Statek(100));

    Paletowy_ptr p(new Paletowy("P1",2 ,1));
    Luzny_ptr l(new Luzny("L1", 5));

    s->dodajLadunek(p);
    s->dodajLadunek(l);

    cout<<s->toString()<<endl;

    cout<<s->pobierzLiczbeLadunkow()<<endl;
    cout<<s->pobierzLacznaMaseLadunkow()<<endl;
    cout<<s->pobierzSredniaMaseLadunkow()<<endl;

    return 0;
}