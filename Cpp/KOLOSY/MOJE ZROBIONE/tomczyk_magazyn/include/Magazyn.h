#ifndef TOMCZYK_MAGAZYN_MAGAZYN_H
#define TOMCZYK_MAGAZYN_MAGAZYN_H
#include <iostream>
#include <memory>
#include <vector>
#include "Opakowanie.h"

class Magazyn
{
    //POLA
    double pojemnosc;

public:

    std::vector<OpakowaniePtr> opakowania;

    explicit Magazyn(double pojemnosc);

    virtual ~Magazyn();

    double getPojemnosc() const;

    void setPojemnosc(double pojemnosc);

    bool wstaw(OpakowaniePtr opakowanie);
    bool wyjmij(OpakowaniePtr opakowanie);


    double dostepnaPojemnosc();
    int liczbaOpakowan();

    std::string opis();

};
typedef std::shared_ptr<Magazyn> Magazyn_ptr;
#endif //TOMCZYK_MAGAZYN_MAGAZYN_H
