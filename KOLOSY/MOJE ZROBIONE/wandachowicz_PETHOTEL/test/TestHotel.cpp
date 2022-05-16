#include <boost/test/unit_test.hpp>

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Hotel.h"

BOOST_AUTO_TEST_SUITE(HotelTests)

BOOST_AUTO_TEST_CASE(testHotel_NoAnimals_ZeroTotalCost) {
    Hotel_ptr hotel(new Hotel());
    BOOST_CHECK_EQUAL(hotel->getAnimalsCount(), 0);
}

BOOST_AUTO_TEST_CASE(testHotel) {
        Hotel_ptr hotel(new Hotel());
        Animal_ptr kot1(new Cat("Puszek1", 1 , false));
        Animal_ptr kot2(new Cat("Puszek2", 1 , true));
        Animal_ptr dog1(new Dog("Fafik1" , 2));
        Animal_ptr dog2(new Dog("Fafik2" , 3));
        hotel->addAnimal(kot1);
        hotel->addAnimal(kot2);
        hotel->addAnimal(dog1);
        hotel->addAnimal(dog2);
        BOOST_CHECK_EQUAL(hotel->getAnimalsCount() , 4);
        BOOST_CHECK_EQUAL(hotel->getTotalCost() ,  740);
}
BOOST_AUTO_TEST_SUITE_END()
