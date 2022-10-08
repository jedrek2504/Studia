//
// Created by student on 16.05.2022.
//

#ifndef KWAPISZ_OWOCKI_JABLKO_H
#define KWAPISZ_OWOCKI_JABLKO_H
#include <iostream>
#include <memory>
#include "Owoc.h" //

class Jablko :public Owoc  //
{
public:
    Jablko(float waga, float cenaZaKilogram);

    virtual ~Jablko();

    std::string toString() override;

};
typedef std::shared_ptr<Jablko> Jablko_ptr;
#endif //KWAPISZ_OWOCKI_JABLKO_H
