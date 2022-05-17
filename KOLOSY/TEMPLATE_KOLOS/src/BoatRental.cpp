#include "BoatRental.h"

#include <sstream>

using namespace std;

void BoatRental::addBoat(Boat_ptr bptr) {
    boats.push_back(bptr);
}

void BoatRental::rentBoat(int boatId) {
    for(int i=0 ; i<boats.size() ; i++)
    {
        if(boatId == boats[i]->getBoatId())
        {
            boats[i]->setIsAvailable(false);
        }
    }
}

void BoatRental::returnBoat(int boatId) {
    for(int i=0 ; i<boats.size() ; i++)
    {
        if(boatId == boats[i]->getBoatId())
        {
            boats[i]->setIsAvailable(true);
            setAccount(getAccount() + boats[i]->calculateRentalPrice()); //NIE WIEM CZY PRZY ZWRACANIU LODZI
        }
    }
}

std::string BoatRental::showAvailableBoats() {
    stringstream chain;
    chain<<"DOSTEPNE LODZIE:\n";
    for(int i=0 ; i<boats.size() ; i++)
    {
        if(boats[i]->getIsAvailable() == true)
            chain<<boats[i]->getBoatInfo();
    }
    return chain.str();
}

std::string BoatRental::showRentedBoats() {
    stringstream chain;
    chain<<"WYPOZYCZONE LODZIE:\n";
    for(int i=0 ; i<boats.size() ; i++)
    {
        if(boats[i]->getIsAvailable() == false)
            chain<<boats[i]->getBoatInfo();
    }
    return chain.str();
}

BoatRental::BoatRental(int account) : account(account) {}

BoatRental::~BoatRental() {

}

int BoatRental::getAccount() const {
    return account;
}

void BoatRental::setAccount(int account) {
    BoatRental::account = account;
}
