#include <iostream>
#pragma once //z jakeigos powodu naprawia redefincije klasy mimo ze nie ma redefinicji zadnej

using namespace std;

class Address
{
    string city;
    string street;
    string number;

public:
    Address();
    Address(const string &c, const string &s, const string &n); //konstruktor parametrowy

    string getAddressInfo(); //zwraca lancuch informacji o adresie

    //settery
    void setCity(const string &newCity);
    void setStreet(const string &newStreet);
    void setNumber(const string &newNumber);

    //gettery
    const string &getCity() const;
    const string &getStreet() const;
    const string &getNumber() const;
};