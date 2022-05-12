#include "Czasopismo.h"
#include <sstream>

using namespace std;

Czasopismo::Czasopismo(const std::string &nazwa, int rozmiar) : Element(rozmiar), nazwa(nazwa) {}

Czasopismo::~Czasopismo() {

}

const std::string &Czasopismo::getNazwa() const {
    return nazwa;
}

void Czasopismo::setNazwa(const std::string &nazwa) {
    Czasopismo::nazwa = nazwa;
}

std::string Czasopismo::toString() {
    stringstream chain;
    chain<<" "<<"Typ elementu: Czasopismo Autor: "<<getNazwa()<<endl;
    return Element::toString()+chain.str();
}
