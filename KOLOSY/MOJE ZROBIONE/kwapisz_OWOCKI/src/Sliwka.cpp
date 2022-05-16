//
// Created by student on 16.05.2022.
//

#include "Sliwka.h"
#include <sstream>

using namespace std;
std::string Sliwka::toString() {
    stringstream chain;
    chain<<" "<<"Typ Owocu: Sliwka ";
    return chain.str()+Owoc::toString();
}

Sliwka::Sliwka(float waga, float cenaZaKilogram) : Owoc(waga, cenaZaKilogram) {}

Sliwka::~Sliwka() {

}
