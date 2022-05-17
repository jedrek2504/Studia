//
// Created by student on 17.05.2022.
//

#include "Rowboat.h"
#include <sstream>

using namespace std;


std::string Rowboat::getBoatInfo() {
    stringstream chain;
    chain<<" "<<"Typ lodzi: Rowboat"<<" wypornosc lodzi: "<<getDisplacement()<<endl;
    return Boat::getBoatInfo()+chain.str();
}

int Rowboat::calculateRentalPrice() {
    if(getDisplacement() < 200) return 120;
    else return 150;
}

Rowboat::Rowboat(int boatId, const string &name, bool isAvailable, int displacement) : Boat(boatId, name, isAvailable),
                                                                                       displacement(displacement) {}

Rowboat::~Rowboat() {

}

int Rowboat::getDisplacement() const {
    return displacement;
}