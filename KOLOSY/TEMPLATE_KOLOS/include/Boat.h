#ifndef TEMPLATE_ABSTRAKCYJNA_H
#define TEMPLATE_ABSTRAKCYJNA_H




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

    bool getIsAvailable() const; //????

    virtual std::string getBoatInfo();
    virtual int calculateRentalPrice()=0;

};
typedef std::shared_ptr<Boat> Boat_ptr;





#endif
