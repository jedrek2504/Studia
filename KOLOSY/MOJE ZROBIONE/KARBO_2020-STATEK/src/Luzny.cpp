#include <iostream>
#include <sstream>
#include "Luzny.h"

using namespace std;

int Luzny::getMasaLadunku() const {
    return masaLadunku;
}

void Luzny::setMasaLadunku(int masaLadunku) {
    Luzny::masaLadunku = masaLadunku;
}

Luzny::Luzny(string nazwa, int masaLadunku) : Ladunek(nazwa), masaLadunku(masaLadunku) {}

int Luzny::obliczMase() {
    return getMasaLadunku();
}

string Luzny::toString()
{
    stringstream chain;
    chain<<"Typ Ladunku: "<<getNazwa()<<" Laczna masa "<<obliczMase()<<endl;
    return chain.str();
}

Luzny::~Luzny() {

}
