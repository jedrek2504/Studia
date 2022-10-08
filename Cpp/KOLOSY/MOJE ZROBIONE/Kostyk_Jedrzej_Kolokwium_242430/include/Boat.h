//
// Created by student on 17.05.2022.
//

#ifndef START_BOAT_H
#define START_BOAT_H
#include <iostream>
#include <memory>

class Boat
{
protected:
    int boatId;
    std::string name;
    bool isAvailable;
public:
    Boat(int boatId, const std::string &name, bool isAvailable);

    virtual ~Boat();

    void setIsAvailable(bool isAvailable);

    int getBoatId() const;

    const std::string &getName() const;

    bool getIsAvailable() const;

    virtual std::string getBoatInfo();
    virtual int calculateRentalPrice()=0;

};
typedef std::shared_ptr<Boat> Boat_ptr;
#endif //START_BOAT_H
