#include <boost/test/unit_test.hpp>
#include "Rowboat.h"
#include "Sailboat.h"
#include "BoatRental.h"

using namespace std;
namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(BasicModelTestSuite)

    BOOST_AUTO_TEST_CASE(BoatConstructorTest) {
        Rowboat myRB(1, "X15", true, 250);
        BOOST_TEST(myRB.getName() == "X15");
        BOOST_TEST(myRB.calculateRentalPrice() == 150);
        BOOST_TEST(myRB.getIsAvailable());

        Sailboat mySB(2, "Ofra Haza", true, 6);
        BOOST_TEST(mySB.getName() == "Ofra Haza");
        BOOST_TEST(mySB.calculateRentalPrice() == 230);
        BOOST_TEST(mySB.getIsAvailable());

        Sailboat mySB2(3, "Titanic", true, 12);
        BOOST_TEST(mySB2.getName() == "Titanic");
        BOOST_TEST(mySB2.calculateRentalPrice() == 260);
        BOOST_TEST(mySB2.getIsAvailable());
    }

    BOOST_AUTO_TEST_CASE(BoatRentalConstructorTest) {
        BoatRental myBoutRent(20);
        BOOST_TEST(myBoutRent.getAccount() == 20);
    }

BOOST_AUTO_TEST_SUITE_END()
