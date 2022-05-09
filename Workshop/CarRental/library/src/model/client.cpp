#include <iostream>
#include "model/client.h"
#include "model/address.h"

using namespace std;

Client::Client(){}

Client::Client(const string &fn, const string &ln, const string &id, Address *a)
{
    firstName = fn;
    lastName = ln;
    personalID = id;
    address = a;
}

string Client::getClientInfo()
{
    string clientInfo = firstName+" "+lastName+" "+personalID+" "+address->getAddressInfo();
    return clientInfo;
}

string Client::getClientFullInfo()
{
    string clientInfo = this->getClientInfo()+" "+this->getCurrentRents();
    return clientInfo;
}

void Client::setFirstName(const string &newFirstName)
{
    if(newFirstName.length() > 0) firstName = newFirstName;
    else return;
}
void Client::setLastName(const string &newLastName)
{
    if(newLastName.length() > 0) lastName = newLastName;
    else return;
}
void Client::setPersonalId(const string &newPersonalId)
{
    if(newPersonalId.length() > 0) personalID = newPersonalId;
    else return;
}

void Client::setAddress(Address *newAddress)
{
    if(newAddress->getCity().length()>0 && newAddress->getStreet().length()>0 && newAddress->getNumber().length()>0)
    {
        address = newAddress;
    }
    else return;
}


void Client::setCurrentRents(Rent *cR) {
    currentRents.push_back(cR);
}

const string &Client::getFirstName() const
{
    return firstName;
}
const string &Client::getLastName() const
{
    return lastName;
}
const string &Client::getPersonalId() const
{
    return personalID;
}

const Address *Client::getAddress() const
{
    return address;
}

const string &Client::getCurrentRents() const {
    string *currentRentId = new string;
    for(int i=0 ; i<currentRents.size() ; i++)
    {
        *currentRentId += to_string(currentRents[i]->getId())+" ";
    }
    return *currentRentId;
}

Client::~Client()
{
}



