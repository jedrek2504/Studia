#include "Towarowy.h"
#include <sstream>

using namespace std;

std::string Towarowy::toString() {
    stringstream chain;
    chain<<Wagon::toString()<<" Pojemnosc skrzyni: "<<getPojemnoscSkrzyni()<<'\n';
    return chain.str();
}

Towarowy::Towarowy(int masaDopuszczalna, int pojemnoscSkrzyni) : Wagon(masaDopuszczalna),
                                                                 pojemnoscSkrzyni(pojemnoscSkrzyni) {}

Towarowy::~Towarowy() {

}

int Towarowy::getPojemnoscSkrzyni() const {
    return pojemnoscSkrzyni;
}

void Towarowy::setPojemnoscSkrzyni(int pojemnoscSkrzyni) {
    Towarowy::pojemnoscSkrzyni = pojemnoscSkrzyni;
}
