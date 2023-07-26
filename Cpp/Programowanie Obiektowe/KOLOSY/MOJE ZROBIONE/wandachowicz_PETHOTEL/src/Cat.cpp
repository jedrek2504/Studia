#include "Cat.h"

Cat::Cat(const std::string &name, unsigned int days, bool premium) : Animal(name, days), premium(premium) {}

bool Cat::getPremium() const {
    return premium;
}

double Cat::getCost() {
    if(getPremium() == 0) return 90.0*getDays();
    else return 150.0*getDays();
}
