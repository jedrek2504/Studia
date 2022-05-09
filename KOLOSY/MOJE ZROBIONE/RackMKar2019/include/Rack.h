#ifndef RACKMKAR2019_RACK_H
#define RACKMKAR2019_RACK_H
#include <iostream>
#include <memory>
#include <vector>
#include "Polka.h"

class Rack
{
    int mocChlodzenia;
    std::vector<PolkaPtr> polki;

public:
    explicit Rack(int mocChlodzenia);
    virtual ~Rack();

    int getMocChlodzenia() const;
    void setMocChlodzenia(int mocChlodzenia);

    std::string toString();

    bool dodajPolke(PolkaPtr polka);
    bool usunPolke(PolkaPtr polka);
    int obliczLiczbePolek();
    int obliczLacznaMocPolek();
};
typedef std::shared_ptr<Rack> RackPtr; //smartpointer rack

#endif //RACKMKAR2019_RACK_H
