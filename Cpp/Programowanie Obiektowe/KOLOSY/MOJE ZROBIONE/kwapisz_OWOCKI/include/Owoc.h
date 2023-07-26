//
// Created by student on 16.05.2022.
//

#ifndef KWAPISZ_OWOCKI_OWOC_H
#define KWAPISZ_OWOCKI_OWOC_H
#include <iostream>
#include <memory>

class Owoc
{
protected:

    float waga;
    float CenaZaKilogram;
public:
    Owoc(float waga, float cenaZaKilogram);

    virtual ~Owoc();

    virtual std::string toString();

    float getWaga() const;

    float getCenaZaKilogram() const;

    virtual float getCena();
};
typedef std::shared_ptr<Owoc> Owoc_ptr; //
#endif //KWAPISZ_OWOCKI_OWOC_H
