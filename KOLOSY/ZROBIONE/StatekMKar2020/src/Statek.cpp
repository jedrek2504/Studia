#include "Statek.hpp"
#include "Ladunek.hpp"
#include <sstream>

Statek::Statek(uint32_t ladownosc) : ladownosc(ladownosc){

}

uint32_t Statek::pobierzLiczbeLadunkow() const {
    return statek.size();
}

uint32_t Statek::pobierzLacznaMaseLadunkow() const {
    uint32_t masa = 0;
    for(const auto &ladunek : statek)
    {
        masa+=ladunek->obliczMase();
    }
    return masa;
}

double Statek::pobierzSredniaMaseLadunkow() const {
    if(pobierzLiczbeLadunkow() > 0)
    {
        return pobierzLacznaMaseLadunkow() / pobierzLiczbeLadunkow();
    }

    return 0;
}

std::string Statek::toString() const {
    std::stringstream info;
    for(const auto &ladunek : statek)
    {
        info << ladunek->toString();
    }
    return info.str();
}

bool Statek::dodajLadunek(const ladunekPtr &ladunek) {
    if(ladunek->obliczMase()+pobierzLacznaMaseLadunkow()<=ladownosc)
    {
        statek.push_back(ladunek);
        return true;
    }
    return false;
}

bool Statek::usunLadunek(ladunekPtr &ladunek) {
    uint32_t it = 0;
    for(auto &zaladowany : statek)
    {
        if(zaladowany == ladunek)
        {
            statek.erase(statek.begin()+it);
            return true;
        }
        ++it;
    }
    return false;
}

