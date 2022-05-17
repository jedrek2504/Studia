#ifndef TEMPLATE_POCHODNA2_H
#define TEMPLATE_POCHODNA2_H

#include <iostream>
#include <memory>
#include "Boat.h"

class Sailboat :public Boat
{
    int sailArea;

public:
    Sailboat(int boatId, const std::string &name, bool isAvailable, int sailArea);

    virtual ~Sailboat();

    int getSailArea() const;

    std::string getBoatInfo() override;
    int calculateRentalPrice() override;

};
typedef std::shared_ptr<Sailboat> Sailboat_ptr;


#endif
