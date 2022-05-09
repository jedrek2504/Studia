#include "model/vehicle.h"

using namespace std;

Vehicle::Vehicle(const string &pn, const unsigned int &bp)
{
    plateNumber = pn;
    basePrice = bp;
}

string Vehicle::getVehicleInfo()
{
    string StringBasePrice = to_string(basePrice);
    return plateNumber+" "+StringBasePrice;
}

void Vehicle::setPlateNumber(const string &newPlateNumber)
{
    if(newPlateNumber.length() > 0) plateNumber = newPlateNumber;
    else return;
}

void Vehicle::setBasePrice(const unsigned int &newBasePrice)
{
    basePrice = newBasePrice;
}

void Vehicle::setRented(bool rented) {
    Vehicle::rented = rented;
}

const string &Vehicle::getPlateNumber() const
{
    return plateNumber;
}

const unsigned int &Vehicle::getBasePrice() const
{
    return basePrice;
}

bool Vehicle::isRented() const {
    return rented;
}