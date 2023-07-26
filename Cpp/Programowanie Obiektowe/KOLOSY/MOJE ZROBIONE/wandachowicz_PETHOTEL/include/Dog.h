//
// Created by student on 16.05.2022.
//

#ifndef WANDACHOWICZ_PETHOTEL_DOG_H
#define WANDACHOWICZ_PETHOTEL_DOG_H
#include <iostream>
#include <memory>
#include "Animal.h"
class Dog :public Animal
{
public:
    Dog(const std::string &name, unsigned int days);

    double getCost() override;

};
typedef std::shared_ptr<Dog> Dog_ptr; //
#endif //WANDACHOWICZ_PETHOTEL_DOG_H
