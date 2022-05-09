#include <iostream>
#include "Macierz.h"
#include <sstream>

using namespace std;


Macierz::Macierz(const string &nazwa, int mocDysku, int liczbaDyskow) : Polka(nazwa), mocDysku(mocDysku),
                                                                        liczbaDyskow(liczbaDyskow) {}

Macierz::~Macierz() {

}

int Macierz::getMocDysku() const{
    return mocDysku;
}

int Macierz::getLiczbaDyskow() const{
    return liczbaDyskow;
}

void Macierz::setMocDysku(int mocDysku) {
    Macierz::mocDysku = mocDysku;
}

void Macierz::setLiczbaDyskow(int liczbaDyskow) {
    Macierz::liczbaDyskow = liczbaDyskow;
}

int Macierz::obliczWydzielanaMoc() {
    return getMocDysku()*getLiczbaDyskow();
}

std::string Macierz::toString() {
    stringstream chain;
    chain<<Polka::toString()<<" Liczba dyskow: "<<getLiczbaDyskow()<<" Moc dysku: "<<getMocDysku()<<" Wydzielana Moc: "<<obliczWydzielanaMoc()<<endl;
    return chain.str();
}
