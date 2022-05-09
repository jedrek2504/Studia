#include <iostream>
#include <sstream>
#include "Paletowy.h"

using namespace std;

int Paletowy::getLiczbaPalet()  {
    return liczbaPalet;
}

int Paletowy::getMasaPalety()  {
    return masaPalety;
}

void Paletowy::setLiczbaPalet(int liczbaPalet) {
    Paletowy::liczbaPalet = liczbaPalet;
}

void Paletowy::setMasaPalety(int masaPalety) {
    Paletowy::masaPalety = masaPalety;
}

int Paletowy::obliczMase()
{
    return getLiczbaPalet()*getMasaPalety();
}

string Paletowy::toString()
{
    stringstream chain;
    chain<<"Typ Ladunku: "<<getNazwa()<<" Liczba Palet: "<<getLiczbaPalet()<<" Masa palety: "<<getMasaPalety()<< " Laczna masa "<<obliczMase()<<endl;
    return chain.str();
}

Paletowy::~Paletowy() {

}

Paletowy::Paletowy(string nazwa, int liczbaPalet, int masaPalety) : Ladunek(nazwa), liczbaPalet(liczbaPalet),
                                                                           masaPalety(masaPalety) {}




