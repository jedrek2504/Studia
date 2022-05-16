

#include "Animal.h"

Animal::Animal(const std::string &name, unsigned int days) : name(name), days(days) {}

Animal::~Animal() {

}

const std::string &Animal::getName() const {
    return name;
}

unsigned int Animal::getDays() const {
    return days;
}
