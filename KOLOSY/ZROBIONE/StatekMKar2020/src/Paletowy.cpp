#include "Paletowy.hpp"
#include <sstream>
#include <utility>

Paletowy::Paletowy(std::string nazwa, uint32_t masa, uint32_t ilosc) : masaPalety(masa), liczbaPalet(ilosc){
    this->nazwa = std::move(nazwa);
}

uint32_t Paletowy::obliczMase() const {
    return masaPalety * liczbaPalet;
}

std::string Paletowy::toString() const {
    std::stringstream info;
    info << "Nazwa: " << nazwa << "\tLadunek Paletowy: masa: " << obliczMase() << " ilosc palet: "  << liczbaPalet << std::endl;
    return info.str();
}
uint32_t Paletowy::getMasaPalety() {
    return masaPalety;
}
uint32_t Paletowy::getLiczbaPalet() {
    return liczbaPalet;
}
