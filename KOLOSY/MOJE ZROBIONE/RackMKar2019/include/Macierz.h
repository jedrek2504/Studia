#ifndef RACKMKAR2019_MACIERZ_H
#define RACKMKAR2019_MACIERZ_H
#include <iostream>
#include <memory>
#include "Polka.h"

class Macierz :public Polka
{
    int mocDysku;
    int liczbaDyskow;
public:
    Macierz(const std::string &nazwa, int mocDysku, int liczbaDyskow);
    virtual ~Macierz();

    int getMocDysku() const;
    int getLiczbaDyskow() const;

    void setMocDysku(int mocDysku);
    void setLiczbaDyskow(int liczbaDyskow);

    std::string toString() override;
    int obliczWydzielanaMoc() override;
};
typedef std::shared_ptr<Macierz> MacierzPtr; //smartpointer macierz


#endif //RACKMKAR2019_MACIERZ_H
