//
// Created by student on 14.05.2022.
//

#include "Element.h"
#include <sstream>

using namespace std;

std::string Element::toString() {
    stringstream chain;
    chain<<"Rozmiar elementu: "<<getRozmiar();
    return chain.str();
}

Element::Element(int rozmiar) : rozmiar(rozmiar) {}

Element::~Element() {

}

int Element::getRozmiar() const {
    return rozmiar;
}
