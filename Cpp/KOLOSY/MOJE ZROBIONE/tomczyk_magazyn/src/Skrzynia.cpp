#include "../include/Skrzynia.h"
#include <sstream>

using namespace std;

std::string Skrzynia::opis() {
    stringstream chain;
    chain<<" Typ ladunku: Skrzynia "<<"Szerokosc: "<<getSzerokosc()<<" Wysokosc: "<<getWysokosc()<<" Glebokosc: "<<getGlebokosc()<<" Objetosc: "<<objetosc()<<endl;
    return Opakowanie::opis()+chain.str();
}

double Skrzynia::objetosc() {
    return getWysokosc()*getGlebokosc()*getSzerokosc();
}

Skrzynia::Skrzynia(int id, double wysokosc, double szerokosc, double glebokosc) : Opakowanie(id), wysokosc(wysokosc),
                                                                                   szerokosc(szerokosc),
                                                                                   glebokosc(glebokosc) {}

Skrzynia::~Skrzynia() {

}

double Skrzynia::getWysokosc() const {
    return wysokosc;
}

void Skrzynia::setWysokosc(double wysokosc) {
    Skrzynia::wysokosc = wysokosc;
}

double Skrzynia::getSzerokosc() const {
    return szerokosc;
}

void Skrzynia::setSzereokosc(double szerokosc) {
    Skrzynia::szerokosc = szerokosc;
}

double Skrzynia::getGlebokosc() const {
    return glebokosc;
}

void Skrzynia::setGlebokosc(double glebokosc) {
    Skrzynia::glebokosc = glebokosc;
}
