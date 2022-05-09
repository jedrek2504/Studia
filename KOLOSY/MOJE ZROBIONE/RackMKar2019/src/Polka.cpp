#include <iostream>
#include "Polka.h"

using namespace std;

Polka::Polka(const string &nazwa) : nazwa(nazwa) {}

Polka::~Polka() {

}

std::string Polka::toString() { //fajnie jest tak zrobic wsm
    return "Nazwa polki: " + getNazwa();
}

string Polka::getNazwa(){
    return nazwa;
}
