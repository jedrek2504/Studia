#ifndef RACKMKAR2019_POLKA_H
#define RACKMKAR2019_POLKA_H
#include <iostream>
#include <memory>

class Polka
{
    std::string nazwa;

public:
    explicit Polka(const std::string &nazwa);
    virtual ~Polka();
    std::string getNazwa();
    virtual std::string toString();
    virtual int obliczWydzielanaMoc()=0;
};

typedef std::shared_ptr<Polka> PolkaPtr; //samrtpointer polka

#endif
