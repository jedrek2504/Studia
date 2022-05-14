//
// Created by student on 14.05.2022.
//

#ifndef KOLOKWIUM_BIURO_H
#define KOLOKWIUM_BIURO_H
#include <iostream>
#include <memory>
#include "Lokal.h"

class Biuro :public Lokal
{
    double koszty_dodatkowe;

public:
    Biuro(double powierzchnia, double stawka, double koszty);

    double getKosztyDodatkowe() const;

    void setKosztyDodatkowe(double kosztyDodatkowe);

    std::string toString() override;

    double czynsz() override;

};
typedef std::shared_ptr<Biuro> Biuro_ptr;
#endif
