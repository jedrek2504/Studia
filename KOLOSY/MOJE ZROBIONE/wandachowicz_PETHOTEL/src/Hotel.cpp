//
// Created by student on 16.05.2022.
//

#include "Hotel.h"
using namespace std;

void Hotel::addAnimal(Animal_ptr animal) {
    animals.push_back(animal);
}

unsigned int Hotel::getAnimalsCount() {
    return animals.size();
}

double Hotel::getTotalCost() {
    double suma=0;
    for(int i=0 ; i<animals.size() ; i++)
        suma+=animals[i]->getCost();
    return suma;
}

void Hotel::displayAnimals() {
    for(auto & animal : animals)
        cout<<"zwierze o imieniu: "<<animal->getName()<<" liczba dni: "<<animal->getDays()<<" laczna kwota do zaplaty: "<<animal->getCost()<<endl;
}
