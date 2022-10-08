#include <iostream>
#include "Rack.h"
#include <sstream>

using namespace std;

Rack::Rack(int mocChlodzenia) : mocChlodzenia(mocChlodzenia) {}

Rack::~Rack() {

}

void Rack::setMocChlodzenia(int mocChlodzenia) {
    Rack::mocChlodzenia = mocChlodzenia;
}

int Rack::getMocChlodzenia() const {
    return mocChlodzenia;
}

std::string Rack::toString() {
    stringstream chain;
    chain<<"INFORMACJE O RACKU:\n";
    chain<<"Moc chlodzenia: "<<getMocChlodzenia()<<'\n';
    chain<<"\tPolki: \n";
    for(int i=0 ; i<polki.size() ; i++)
        chain<<polki[i]->toString();
    return chain.str();
}

bool Rack::dodajPolke(PolkaPtr polka) {
    if(polka->obliczWydzielanaMoc()+obliczLacznaMocPolek()<=getMocChlodzenia()) {
        polki.push_back(polka);
        return true;
    }
    else return false;
}

int Rack::obliczLiczbePolek() {
    return polki.size();
}

int Rack::obliczLacznaMocPolek() {
    int suma=0;
    for(auto & i : polki) suma+=i->obliczWydzielanaMoc();
    return suma;

}

bool Rack::usunPolke(PolkaPtr polka) {
    for(int i=0 ; i<polki.size() ; i++)
    {
        if(polki[i] == polka)
        {
            polki[i] = nullptr;
            polki.erase(polki.begin() + i);
            return true;
        }
    }
    return false;
}
