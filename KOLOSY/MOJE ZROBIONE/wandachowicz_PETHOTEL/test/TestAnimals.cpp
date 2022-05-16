#include <boost/test/unit_test.hpp>

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

BOOST_AUTO_TEST_SUITE(AnimalsTests)

BOOST_AUTO_TEST_CASE(testNormalCat_OneDay_ExpectedCost) {
    Cat c("Tom", 1, false);
    BOOST_CHECK_EQUAL(c.getCost(), 90.0);
}

BOOST_AUTO_TEST_CASE(testPremiumCat_TwoDays_ExpectedCost) {
    Cat c("King", 2, true);
    BOOST_CHECK_EQUAL(c.getCost(), 2 * 150.0);
}

BOOST_AUTO_TEST_CASE(testDog_ThreeDays_ExpectedCost) {
    Dog d("Fido", 3);
    BOOST_CHECK_EQUAL(d.getCost(), 3 * 100.0);
}

BOOST_AUTO_TEST_SUITE_END()
