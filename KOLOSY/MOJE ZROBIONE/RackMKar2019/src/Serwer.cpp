#include <iostream>
#include "Serwer.h"
#include <sstream>

using namespace std;

Serwer::Serwer(const string &nazwa, int mocCalkowita) : Polka(nazwa), mocCalkowita(mocCalkowita) {}

Serwer::~Serwer() {

}

int Serwer::getMocCalkowita(){
    return mocCalkowita;
}

void Serwer::setMocCalkowita(int mocCalkowita) {
    Serwer::mocCalkowita = mocCalkowita;
}

std::string Serwer::toString() {
    stringstream chain;
    chain<<Polka::toString()<<" Wydzielana Moc: "<<obliczWydzielanaMoc()<<endl;
    return chain.str();
}

int Serwer::obliczWydzielanaMoc() {
    return getMocCalkowita();
}
