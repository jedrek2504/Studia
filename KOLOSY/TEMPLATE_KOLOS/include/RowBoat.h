#ifndef TEMPLATE_POCHODNA1_H
#define TEMPLATE_POCHODNA1_H




#include <iostream>
#include <memory>
#include "Boat.h"

class Rowboat :public Boat
{
    int displacement;

public:
    Rowboat(int boatId, const std::string &name, bool isAvailable, int displacement);

    virtual ~Rowboat();

    int getDisplacement() const;

    std::string getBoatInfo() override;
    int calculateRentalPrice() override;

};
typedef std::shared_ptr<Rowboat> Rowboat_ptr;




#endif
