#include "BoatRental.h"

#include <sstream>

using namespace std;
/*
int BoatRental::pobierzLiczbe() { //

    return elementy.size(); //

}

int BoatRental::pobierzLaczna() {

    int suma=0;
    for(int i=0 ; i<elementy.size() ; i++) //
        suma+=elementy[i]->getWirtualnaZmienna(); //
    return suma;

}

float BoatRental::pobierzSrednia() {

    if(pobierzLiczbe()!=0) return (float)pobierzLaczna()/(float)pobierzLiczbe(); //
    else return 0;

}

bool BoatRental::dodaj(Abstrakcyjna_ptr element) {

    if(element->getWirtualnaZmienna()+pobierzLaczna() <= getPojemnosc()) //
    {
        elementy.push_back(element);
        return true;
    }
    else return false;

}

bool BoatRental::usun(Abstrakcyjna_ptr element) {

    for(int i=0 ; i<elementy.size() ; i++) //
    {
        if(elementy[i] == element) //
        {
            elementy[i] = nullptr; //
            elementy.erase(elementy.begin()+i); //
            return true;
        }
    }
    return false;

}

std::string BoatRental::toString() {

    stringstream chain;
    chain<<"INFORMACJE O GLOWNA\n"; //
    chain<<"Pojemnosc GLOWNEJ: "<<getPojemnosc()<<endl; //
    chain<<"\tElementy:\n"; //
    for(int i=0 ; i<elementy.size() ; i++)
        chain<<elementy[i]->toString();
    chain<<"KOMENTARZ"<<pobierzLiczbe()<<endl;
    chain<<"KOMENTARZ"<<pobierzLaczna()<<endl;
    return chain.str();

}
*/

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
        if(boats[i]->getAvailable() == true)
            chain<<boats[i]->getBoatInfo();
    }
    return chain.str();
}

std::string BoatRental::showRentedBoats() {
    stringstream chain;
    chain<<"WYPOZYCZONE LODZIE:\n";
    for(int i=0 ; i<boats.size() ; i++)
    {
        if(boats[i]->getAvailable() == false)
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
