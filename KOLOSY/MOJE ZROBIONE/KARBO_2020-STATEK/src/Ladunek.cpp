#include <iostream>
#include "Ladunek.h"
#include <sstream>

using namespace std;

const std::string &Ladunek::getNazwa() const {
    return nazwa;
}

void Ladunek::setNazwa(const std::string &nazwa) {
    Ladunek::nazwa = nazwa;
}

Ladunek::Ladunek(std::string nazwa) : nazwa(nazwa) {}

Ladunek::~Ladunek() {

}
