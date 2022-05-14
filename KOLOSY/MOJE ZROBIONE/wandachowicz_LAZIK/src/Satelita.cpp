//
// Created by student on 14.05.2022.
//

#include "Satelita.h"
#include <sstream>

using namespace std;

std::string Satelita::toString() {
    stringstream chain;
    chain<<" "<<"Typ elementu: Satelita"<<" Wlasciciel: "<<getWlasciciel()<<endl;
    return Element::toString()+chain.str();
}

Satelita::Satelita(int rozmiar, const std::string &wlasciciel) : Element(rozmiar), wlasciciel(wlasciciel) {}

Satelita::~Satelita() {

}

const std::string &Satelita::getWlasciciel() const {
    return wlasciciel;
}
