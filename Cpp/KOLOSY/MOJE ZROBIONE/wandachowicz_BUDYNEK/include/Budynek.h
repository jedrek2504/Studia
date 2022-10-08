//
// Created by student on 14.05.2022.
//

#ifndef KOLOKWIUM_BUDYNEK_H
#define KOLOKWIUM_BUDYNEK_H
#include <iostream>
#include <memory>
#include <vector>
#include "Lokal.h" //

class Budynek //
{
    std::vector<Lokal_ptr> lokale;

public:
    Budynek();

    virtual ~Budynek();

    void dodaj_lokal(Lokal_ptr lokal);

    double czynsz_calkowity();

    std::string toString(); //NIE MA NA UML (?)

    double zysk(double wydatki_za_metr);



};
typedef std::shared_ptr<Budynek> Budynek_ptr;
#endif //KOLOKWIUM_BUDYNEK_H
