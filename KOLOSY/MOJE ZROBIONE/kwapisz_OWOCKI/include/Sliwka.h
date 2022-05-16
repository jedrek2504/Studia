//
// Created by student on 16.05.2022.
//

#ifndef KWAPISZ_OWOCKI_SLIWKA_H
#define KWAPISZ_OWOCKI_SLIWKA_H
#include <iostream>
#include <memory>
#include "Owoc.h" //

class Sliwka :public Owoc  //
{
public:
    Sliwka(float waga, float cenaZaKilogram);

    virtual ~Sliwka();

    std::string toString() override;



};
typedef std::shared_ptr<Sliwka> Sliwka_ptr; //


#endif //KWAPISZ_OWOCKI_SLIWKA_H
