//
// Created by student on 16.05.2022.
//

#ifndef KWAPISZ_OWOCKI_SKRZYNKA_H
#define KWAPISZ_OWOCKI_SKRZYNKA_H
#include <iostream>
#include <memory>
#include <vector>
#include "Owoc.h" //

class Skrzynka //
{
    //POLA
    int maxLadownosc;
    std::vector<Owoc_ptr> owoce; //

public:
    explicit Skrzynka(int maxLadownosc);

    int getMaxLadownosc() const;

    bool wlozOwoc(Owoc_ptr owoc);
    bool usunOwoc(Owoc_ptr owoc);

    //
    float pobierzCenaCalkowita();
    float pobierzMasaCalkowita();

    std::string toString();

};
typedef std::shared_ptr<Skrzynka> Skrzynka_ptr;

#endif //KWAPISZ_OWOCKI_SKRZYNKA_H
