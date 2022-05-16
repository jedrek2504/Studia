#include <iostream>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Hotel.h"

using namespace std;

int main() {
    cout << "Renting of premises" << endl;


    // Write rest of the program here:
    Hotel_ptr hotel(new Hotel());
    Animal_ptr kot1(new Cat("Puszek1", 1 , false));
    Animal_ptr kot2(new Cat("Puszek2", 1 , true));
    Animal_ptr dog1(new Dog("Fafik1" , 2));
    Animal_ptr dog2(new Dog("Fafik2" , 3));
    hotel->addAnimal(kot1);
    hotel->addAnimal(kot2);
    hotel->addAnimal(dog1);
    hotel->addAnimal(dog2);
    hotel->displayAnimals();

    return 0;
}
