#include "Wagon.h"
#include <sstream>

using namespace std;

std::string Wagon::toString() {
    stringstream chain;
    chain<<"Masa dopuszczalna wagonu: "<<getMasaDopuszczalna();
    return chain.str();
}

Wagon::Wagon(int masaDopuszczalna) : masaDopuszczalna(masaDopuszczalna) {}

int Wagon::getMasaDopuszczalna() const {
    return masaDopuszczalna;
}

void Wagon::setMasaDopuszczalna(int masaDopuszczalna) {
    Wagon::masaDopuszczalna = masaDopuszczalna;
}

Wagon::~Wagon() {

}
