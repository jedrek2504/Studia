#include "Element.h"
#include <sstream>

using namespace std;

Element::Element(int rozmiar) : rozmiar(rozmiar) {}

Element::~Element() {

}

int Element::getRozmiar() const {
    return rozmiar;
}

void Element::setRozmiar(int rozmiar) {
    Element::rozmiar = rozmiar;
}

std::string Element::toString() {
    stringstream chain;
    chain<<"Rozmiar elementu: "<<getRozmiar();
    return chain.str();
}
