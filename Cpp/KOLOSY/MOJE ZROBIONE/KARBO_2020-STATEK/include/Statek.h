#ifndef START_STATEK_STATEK_H
#define START_STATEK_STATEK_H
#include <iostream>
#include "Ladunek.h"
#include <memory>
#include <vector>

class Statek
{
    int ladownosc;
    std::vector<Ladunek_ptr> ladunki;

public:
    Statek(int ladownosc);

    int getLadownosc() const;
    std::string getLadunkiInfo();

    void setLadownosc(int ladownosc);

    bool dodajLadunek(Ladunek_ptr ladunek);
    bool usunLadunek(Ladunek_ptr ladunek);
    int pobierzLiczbeLadunkow();
    int pobierzLacznaMaseLadunkow();
    double pobierzSredniaMaseLadunkow();
    std::string toString();
};
typedef std::shared_ptr<Statek> Statek_ptr;
#endif
