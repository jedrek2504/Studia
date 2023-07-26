#include <boost/test/unit_test.hpp>
#include "Rowboat.h"
#include "Sailboat.h"
#include "BoatRental.h"

using namespace std;
namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(BoatRentalTest)

    BOOST_AUTO_TEST_CASE(RentBoatTest) {
    BoatRental_ptr boatrental(new BoatRental(50));
    Boat_ptr myRB(new Rowboat(1, "X15", true, 250));
    boatrental->addBoat(myRB);
    boatrental->rentBoat(1);
    BOOST_TEST(boatrental->getAccount() == 200);
    boatrental->rentBoat(1);
    BOOST_TEST(boatrental->getAccount() == 200);
    }
    BOOST_AUTO_TEST_CASE(ReturnBoatTest) {
    BoatRental_ptr boatrental(new BoatRental(50));
    Boat_ptr mySB(new Sailboat(1, "X15", true, 6));
    boatrental->addBoat(mySB);
    boatrental->rentBoat(1);
    BOOST_TEST(boatrental->getAccount() == 230+50);
    boatrental->returnBoat(1);
    BOOST_TEST(mySB->getIsAvailable() == true);
    }
BOOST_AUTO_TEST_SUITE_END()
