//
// Created by student on 16.05.2022.
//

#ifndef WANDACHOWICZ_PETHOTEL_ANIMAL_H
#define WANDACHOWICZ_PETHOTEL_ANIMAL_H
#include <iostream>
#include <memory>

class Animal //
{
protected:
    std::string name;
    unsigned int days;
public:
    Animal(const std::string &name, unsigned int days);

    virtual ~Animal();

    const std::string &getName() const;

    unsigned int getDays() const;

    virtual double getCost()=0;
};
typedef std::shared_ptr<Animal> Animal_ptr; //

#endif
