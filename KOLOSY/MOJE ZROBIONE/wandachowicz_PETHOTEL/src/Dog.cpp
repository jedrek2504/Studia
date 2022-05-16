//
// Created by student on 16.05.2022.
//

#include "Dog.h"

Dog::Dog(const std::string &name, unsigned int days) : Animal(name, days) {}

double Dog::getCost() {
    return 100*getDays();
}
