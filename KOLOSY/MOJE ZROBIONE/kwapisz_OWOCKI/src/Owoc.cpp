//
// Created by student on 16.05.2022.
//

#include "Owoc.h"
#include <sstream>

using namespace std;

std::string Owoc::toString() {
    stringstream chain;
    chain<<"Masa: "<<getWaga()<<" Cena/kg: "<<getCenaZaKilogram()<<" Cena: "<<getCena()<<endl;
    return chain.str();
}

Owoc::Owoc(float waga, float cenaZaKilogram) : waga(waga), CenaZaKilogram(cenaZaKilogram) {}

Owoc::~Owoc() {

}

float Owoc::getWaga() const {
    return waga;
}

float Owoc::getCenaZaKilogram() const {
    return CenaZaKilogram;
}

float Owoc::getCena() {
    return getWaga()*getCenaZaKilogram();
}
