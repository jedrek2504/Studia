#ifndef clientClass
#define clientClass
#include <iostream>
#include <vector>
#include "rent.h"
#include "address.h"


using namespace std;

class Client
{
    string firstName;
    string lastName;
    string personalID;
    Address *address;
    vector < Rent* > currentRents; //reprezentacja wektora (taka tablica dynamiczna ale jest elastyczny jej rozmiar)

public:
    Client(); //konstruktor bezparametrowy
    Client(const string &fn, const string &ln, const string &id, Address *a); //konstruktor parametrowy zawierający wskaźnik na obiekt klasy Address

    string getClientInfo(); //zwraca łancuch znakow z podanych zmiennych
    string getClientFullInfo(); //zwraca lancuch znakow metody getClientInfo + " " + getCurrentRents

    //settery
    void setFirstName(const string &newFirstName);
    void setLastName(const string &newLastName);
    void setPersonalId(const string &newPersonalId);

    void setAddress(Address *newAddress);

    void setCurrentRents(Rent* cR); //setter dla elementu Rent* wektora currentRents

    //gettery
    const string &getFirstName() const;
    const string &getLastName() const;
    const string &getPersonalId() const;

    const Address *getAddress() const; //zwraca adres(&) na ktory wskazuje pole *address

    const string &getCurrentRents() const; //zwraca id wypozyczen danego klienta + " "

    ~Client(); //destruktor
};
#endif
