#include <boost/test/unit_test.hpp>
#include "model/vehicle.h"

using namespace std;

struct TestSuiteVehicleFixture {
    const string testPlateNumber = "EL 6582TA";
    const unsigned int testBasePrice = 3;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicle, TestSuiteVehicleFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {

        Vehicle v(testPlateNumber, testBasePrice);
        BOOST_TEST(testPlateNumber == v.getPlateNumber());
        BOOST_TEST(testBasePrice == v.getBasePrice());
    }

    BOOST_AUTO_TEST_CASE(VehiclegetPlateNumberTest) {
        Vehicle v(testPlateNumber, testBasePrice);
        BOOST_TEST(v.getPlateNumber() == testPlateNumber);
    }

    BOOST_AUTO_TEST_CASE(VehiclegetBasePrice) {
        Vehicle v(testPlateNumber, testBasePrice);
        BOOST_TEST(v.getBasePrice() == testBasePrice);
    }

    BOOST_AUTO_TEST_CASE(VehiclesetPlateNumber) {
        Vehicle v(testPlateNumber, testBasePrice);
        v.setPlateNumber("123");
        BOOST_TEST(v.getPlateNumber() == "123");
    }

    BOOST_AUTO_TEST_CASE(VehiclesetBasePrice) {
        Vehicle v(testPlateNumber, testBasePrice);
        v.setBasePrice(123);
        BOOST_TEST(v.getBasePrice() == 123);
    }

BOOST_AUTO_TEST_SUITE_END()
