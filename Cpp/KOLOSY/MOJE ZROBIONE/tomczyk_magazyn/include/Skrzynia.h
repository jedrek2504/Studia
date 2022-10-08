#ifndef TOMCZYK_MAGAZYN_SKRZYNIA_H
#define TOMCZYK_MAGAZYN_SKRZYNIA_H
#include <iostream>
#include <memory>
#include "Opakowanie.h"

class Skrzynia :public Opakowanie
{
    //POLE:
    double wysokosc;
    double szerokosc;
    double glebokosc;

public:
    Skrzynia(int id, double wysokosc, double szereokosc, double glebokosc);

    virtual ~Skrzynia();

    double getWysokosc() const;

    void setWysokosc(double wysokosc);

    double getSzerokosc() const;

    void setSzereokosc(double szereokosc);

    double getGlebokosc() const;

    void setGlebokosc(double glebokosc);

    std::string opis() override;
    double objetosc() override;

};
typedef std::shared_ptr<Skrzynia> Skrzynia_ptr;

#endif //TOMCZYK_MAGAZYN_SKRZYNIA_H
