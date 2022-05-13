#include "../include/Pojazd.h"
#include <sstream>

using namespace std;

Pojazd::Pojazd(const std::string &nrRejestracyjny) : nrRejestracyjny(
        nrRejestracyjny) , liczbaPrzejechanychKilometrow(0) {}

Pojazd::~Pojazd() {

}

const std::string &Pojazd::getNrRejestracyjny() const {
    return nrRejestracyjny;
}

void Pojazd::setNrRejestracyjny(const std::string &nrRejestracyjny) {
    Pojazd::nrRejestracyjny = nrRejestracyjny;
}

int Pojazd::getLiczbaPrzejechanychKilometrow() const {
    return liczbaPrzejechanychKilometrow;
}

void Pojazd::setLiczbaPrzejechanychKilometrow(int liczbaPrzejechanychKilometrow) {
    Pojazd::liczbaPrzejechanychKilometrow = liczbaPrzejechanychKilometrow;
}

std::string Pojazd::toString() {
    stringstream chain;
    chain<<"Nr rejestracyjny pojazdu: "<<getNrRejestracyjny()<<" liczba przejcechanych km: "<<getLiczbaPrzejechanychKilometrow();
    return chain.str();
}

