#ifndef vehicleClass
#define vehicleClass
#include <iostream>

using namespace std;

class Vehicle
{
    string plateNumber;
    unsigned int basePrice;
    Vehicle *vehicle;
    bool rented; //czy wypozyczony czy nie

public:

    Vehicle(const string &pn, const unsigned int &bp);

    string getVehicleInfo();

    void setPlateNumber(const string &newPlateNumber);
    void setBasePrice(const unsigned int &newBasePrice);
    void setRented(bool rented); // ustawia wypozyczenie danego pojazdu - w konstruktorze rent automatycznie ustawiana jest wartosc rented = true

    const string &getPlateNumber() const;
    const unsigned int &getBasePrice() const;
    bool isRented() const; //getter dla rented is - specjalny idiom dla booli.

};
#endif
