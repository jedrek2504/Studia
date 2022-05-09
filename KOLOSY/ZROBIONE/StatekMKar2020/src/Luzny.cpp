#include "Luzny.hpp"
#include <sstream>
#include <utility>

Luzny::Luzny(std::string name, uint32_t masa) :masa(masa){
    nazwa = std::move(name);
}

std::string Luzny::toString() const {
    std::ostringstream info;
    info << "Nazwa: " << nazwa << "\tMasa: " << masa << std::endl;
    return info.str();
}
uint32_t Luzny::getMasaLadunku() {
    return masa;
}
uint32_t Luzny::obliczMase() const {
    return masa;
}

