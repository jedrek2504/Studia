//
// Created by student on 17.05.2022.
//

#include "Boat.h"
#include <sstream>

using namespace std;


std::string Boat::getBoatInfo() {
    stringstream chain;
    chain<<"Id lodzi: "<<getBoatId()<<" Nazwa lodzi: "<<getName();
    return chain.str();
}

Boat::Boat(int boatId, const string &name, bool isAvailable) : boatId(boatId), name(name), isAvailable(true) {}

int Boat::getBoatId() const {
    return boatId;
}

const string &Boat::getName() const {
    return name;
}


Boat::~Boat() {

}

void Boat::setIsAvailable(bool isAvailable) {
    Boat::isAvailable = isAvailable;
}

bool Boat::getIsAvailable() const {
    return isAvailable;
}