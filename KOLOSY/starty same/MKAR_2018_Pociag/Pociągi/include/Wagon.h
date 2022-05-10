#ifndef _WAGON_H
#define _WAGON_H
#include <iostream>
#include <memory>

class Wagon
{
    int masaDopuszczalna;
public:
    virtual std::string toString();

    Wagon(int masaDopuszczalna);
    int getMasaDopuszczalna() const;
    void setMasaDopuszczalna(int masaDopuszczalna);
    virtual ~Wagon();
};
typedef std::shared_ptr<Wagon> Wagon_ptr;


#endif //POCIĄGI_WAGON_H
