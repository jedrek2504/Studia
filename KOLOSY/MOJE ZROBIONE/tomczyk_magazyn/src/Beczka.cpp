#include "../include/Beczka.h"
#include <sstream>

using namespace std;

std::string Beczka::opis() {
    stringstream chain;
    chain<<" Typ ladunku: Beczka "<<"Promien: "<<getPromien()<<" Wysokosc: "<<getWysokosc()<<" Objetosc: "<<objetosc()<<endl;
    return Opakowanie::opis()+chain.str(); //
}

Beczka::Beczka(int id, const std::string &promien, double wysokosc) : Opakowanie(id), promien(promien),
                                                                      wysokosc(wysokosc) {}

Beczka::~Beczka() {

}

const std::string &Beczka::getPromien() const {
    return promien;
}

void Beczka::setPromien(const std::string &promien) {
    Beczka::promien = promien;
}

double Beczka::getWysokosc() const {
    return wysokosc;
}

void Beczka::setWysokosc(double wysokosc) {
    Beczka::wysokosc = wysokosc;
}

double Beczka::objetosc() {
    double promienDouble = std::stod(getPromien()); //string to double
    return 2*promienDouble*getWysokosc();
}
