#ifndef START_STATEK_PALETOWY_H
#define START_STATEK_PALETOWY_H
#include <iostream>
#include "Ladunek.h"
#include <memory>

class Paletowy :public Ladunek
{
    int liczbaPalet;
    int masaPalety;
public:
    Paletowy(std::string nazwa, int liczbaPalet, int masaPalety);

    int obliczMase();
    std::string toString();

    int getLiczbaPalet();
    int getMasaPalety();

    void setLiczbaPalet(int liczbaPalet);
    void setMasaPalety(int masaPalety);

    virtual ~Paletowy();
};
typedef std::shared_ptr<Paletowy> Paletowy_ptr;

#endif //START_STATEK_PALETOWY_H
