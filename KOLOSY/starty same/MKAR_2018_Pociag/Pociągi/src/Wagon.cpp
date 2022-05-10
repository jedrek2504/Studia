//
// Created by pobi on 13.12.18.
//

#include "Wagon.h"
#include <sstream>

Wagon::Wagon(int masaDopuszczalna) : masaDopuszczalna(masaDopuszczalna) {}

int Wagon::getMasaDopuszczalna() const {
    return masaDopuszczalna;
}
