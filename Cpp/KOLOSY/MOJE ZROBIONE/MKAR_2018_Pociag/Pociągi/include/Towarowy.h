#ifndef _TOWAROWY_H
#define _TOWAROWY_H
#include <iostream>
#include <memory>
#include "Wagon.h"

class Towarowy :public Wagon
{
    int pojemnoscSkrzyni;
public:
    std::string toString();

    Towarowy(int masaDopuszczalna, int pojemnoscSkrzyni);
    int getPojemnoscSkrzyni() const;
    void setPojemnoscSkrzyni(int pojemnoscSkrzyni);
    virtual ~Towarowy();

};
typedef std::shared_ptr<Towarowy> Towarowy_ptr;

#endif
