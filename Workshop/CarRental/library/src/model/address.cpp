#include <iostream>
#include "model/address.h"

Address::Address(){}

Address::Address(const string &c, const string &s, const string &n)
{
    city = c;
    street = s;
    number = n;
}

string Address::getAddressInfo()
{
    string AddressInfo = city+" "+street+" "+number;
    return AddressInfo;
}

void Address::setCity(const string &newCity)
{
    if(newCity.length() > 0) city = newCity;
    else return;
}
void Address::setStreet(const string &newStreet)
{
    if(newStreet.length() > 0) street = newStreet;
    else return;
}
void Address::setNumber(const string &newNumber)
{
    if(newNumber.length() > 0) number = newNumber;
    else return;
}

const string &Address::getCity() const
{
    return city;
}
const string &Address::getStreet() const
{
    return street;
}
const string &Address::getNumber() const
{
    return number;
}