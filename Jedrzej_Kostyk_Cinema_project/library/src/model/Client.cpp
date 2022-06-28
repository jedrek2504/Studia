#include "model/Client.h"
#include <sstream>
#include "exceptions/ParameterException.h"
using namespace std;

Client::Client(const std::string &firstName, const std::string &lastName, const int &age,
               const std::string &emailAddress) : firstName(firstName), lastName(lastName), age(age),
                                                 emailAddress(emailAddress) {

    setArchive(false); //Podczas tworzenia obiektu Client ustawiamy archiwalnosc klienta na false.

    //exceptions
    if (firstName.empty()) {throw ParameterException("Invalid firstName (can't be empty)!"); }
    if (lastName.empty()) {throw ParameterException("Invalid lastName (can't be empty)!"); }
    if (age <= 0) {throw ParameterException("Invalid age (must be over 0!"); }
    if (emailAddress.empty()) {throw ParameterException("Invalid emailAddress (can't be empty)!"); }
}


Client::~Client() = default;

//getters
const std::string &Client::getFirstName() const {
    return firstName;
}

const std::string &Client::getLastName() const {
    return lastName;
}

const int  &Client::getAge() const {
    return age;
}

bool Client::isArchive() const {
    return archive;
}

const std::string &Client::getEmailAddress() const {
    return emailAddress;
}

//setters
void Client::setEmailAddress(const std::string &emailAddress) {
    if (!emailAddress.empty()) {
        Client::emailAddress = emailAddress;
    }
}

void Client::setLastName(const std::string &lastName) {
    if (!lastName.empty()) {
        Client::lastName = lastName;
    }
}

void Client::setFirstName(const std::string &firstName) {
    if (!firstName.empty()) {
        Client::firstName = firstName;
    }
}

void Client::setAge(const int &age) {
    if(age > 0) {
        Client::age = age;
    }
}

void Client::setArchive(bool newArchive) {
    Client::archive = newArchive;
}

//other methods
std::string Client::getInfo() const {
    std::stringstream chain;
    chain<<"Imie: "<<getFirstName()<<", nazwisko: "<<getLastName()<<", wiek:"<<getAge()<<", adres email: "<<getEmailAddress()<<".";
    if(isArchive()) {   // if zeby bylo widac czy dane klienta zawarte sa w archiwum
        return chain.str() + " Klient jest archiwalny.";
    }
    return chain.str() + " Klient nie jest archiwalny.";
}


