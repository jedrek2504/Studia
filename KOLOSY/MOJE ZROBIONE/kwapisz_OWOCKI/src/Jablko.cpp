//
// Created by student on 16.05.2022.
//

#include "Jablko.h"
#include <sstream>

using namespace std;

std::string Jablko::toString() {
    stringstream chain;
    chain<<" "<<"Typ Owocu: Jablko ";
    return chain.str()+Owoc::toString();
}

Jablko::Jablko(float waga, float cenaZaKilogram) : Owoc(waga, cenaZaKilogram) {}

Jablko::~Jablko() {

}
