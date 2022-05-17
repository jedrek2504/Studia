//
// Created by student on 17.05.2022.
//

#include "Sailboat.h"
#include <sstream>

using namespace std;


std::string Sailboat::getBoatInfo() {
    stringstream chain;
    chain<<" "<<"Typ lodzi: Sailboat"<<" powierzchnia zagla: "<<getSailArea()<<endl;
    return Boat::getBoatInfo()+chain.str();
}

int Sailboat::calculateRentalPrice() {
    return (200 + (5*getSailArea()));
}

Sailboat::Sailboat(int boatId, const string &name, bool isAvailable, int sailArea) : Boat(boatId, name, isAvailable),
                                                                                     sailArea(sailArea) {}

Sailboat::~Sailboat() {

}

int Sailboat::getSailArea() const {
    return sailArea;
}