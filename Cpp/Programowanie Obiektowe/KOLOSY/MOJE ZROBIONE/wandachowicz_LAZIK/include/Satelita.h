//
// Created by student on 14.05.2022.
//

#ifndef KOLOKWIUM_SATELITA_H
#define KOLOKWIUM_SATELITA_H
#include <iostream>
#include <memory>
#include "Element.h"

class Satelita :public Element
{
    std::string wlasciciel;

public:
    Satelita(int rozmiar, const std::string &wlasciciel);

    virtual ~Satelita();

    const std::string &getWlasciciel() const;

    std::string toString() override;
};
typedef std::shared_ptr<Satelita> Satelita_ptr;

#endif //KOLOKWIUM_SATELITA_H
