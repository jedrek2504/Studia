#ifndef _POCIAG_H
#define _POCIAG_H
#include <iostream>
#include <memory>
#include <vector>
#include "Wagon.h"

class Pociag
{
    int masaMaksymalna;
    std::vector<Wagon_ptr> wagony;
public:
    Pociag(int masaMaksymalna);
    virtual ~Pociag();

    std::string toString();
    int getMasaMaksymalna() const;
    void setMasaMaksymalna(int masaMaksymalna);
    bool dodajWagon(Wagon_ptr wagon);
    bool usunWagon(Wagon_ptr wagon);
    int pobierzLiczbeWagonow();
    int pobierzLacznaMaseDopuszczalnaWagonow();
    float pobierzSredniaMaseDopuszczalnaWagonow();

};
typedef std::shared_ptr<Pociag> Pociag_ptr;
#endif
