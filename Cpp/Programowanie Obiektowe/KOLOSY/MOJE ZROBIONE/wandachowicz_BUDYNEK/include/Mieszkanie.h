#ifndef KOLOKWIUM_MIESZKANIE_H
#define KOLOKWIUM_MIESZKANIE_H

#include <iostream>
#include <memory>
#include "Lokal.h"

class Mieszkanie :public Lokal
{
public:
    Mieszkanie(double powierzchnia, double stawka);

    virtual ~Mieszkanie();

    std::string toString() override;

    double czynsz() override;

};
typedef std::shared_ptr<Mieszkanie> Mieszkanie_ptr;

#endif //KOLOKWIUM_MIESZKANIE_H
