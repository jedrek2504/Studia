//
// Created by student on 17.05.2022.
//

#ifndef START_BOATRENTAL_H
#define START_BOATRENTAL_H
#include <iostream>
#include <memory>
#include <vector>
#include "Boat.h"

class BoatRental
{
    int account;
    std::vector<Boat_ptr> boats;
public:
    explicit BoatRental(int account);

    int getAccount() const;

    void setAccount(int account);

    virtual ~BoatRental();

    void addBoat(Boat_ptr bptr);
    void rentBoat(int boatId);
    void returnBoat(int boatId);

    std::string showAvailableBoats();
    std::string showRentedBoats();

};
typedef std::shared_ptr<BoatRental> BoatRental_ptr;

#endif //START_BOATRENTAL_H
