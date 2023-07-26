//
// Created by student on 16.05.2022.
//

#ifndef WANDACHOWICZ_PETHOTEL_HOTEL_H
#define WANDACHOWICZ_PETHOTEL_HOTEL_H
#include <iostream>
#include <memory>
#include <vector>
#include "Animal.h" //

class Hotel //
{
    std::vector<Animal_ptr> animals; //
public:

    void addAnimal(Animal_ptr animal);


    unsigned int getAnimalsCount();
    double getTotalCost();
    void displayAnimals();

};
typedef std::shared_ptr<Hotel> Hotel_ptr;

#endif //WANDACHOWICZ_PETHOTEL_HOTEL_H
