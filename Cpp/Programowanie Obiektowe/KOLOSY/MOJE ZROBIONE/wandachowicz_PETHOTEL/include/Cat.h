//
// Created by student on 16.05.2022.
//

#ifndef WANDACHOWICZ_PETHOTEL_CAT_H
#define WANDACHOWICZ_PETHOTEL_CAT_H
#include <iostream>
#include <memory>
#include "Animal.h" //

class Cat :public Animal  //
{
    bool premium;
public:
    Cat(const std::string &name, unsigned int days, bool premium);

    bool getPremium() const;

    double getCost() override;
};
typedef std::shared_ptr<Cat> Cat_ptr; //
#endif //WANDACHOWICZ_PETHOTEL_CAT_H
