#include <boost/test/unit_test.hpp>
#include "model/vehicle.h"
#include "model/client.h"

struct TestSuiteRentFixture {
    unsigned int testId = 123;
    Vehicle *testvehicle;
    Client *testclient;
    Client *testclient2;
    Address *testaddress;

    TestSuiteRentFixture() {
        testvehicle = new Vehicle("testPlateNumber", 69);
        testaddress = new Address("London", "Accacia Avenue", "22");
        testclient = new Client("Jon", "Arbuckle", "0123456789", testaddress);
        testclient2 = new Client("Jon", "Arbuckle", "0123456789", testaddress);
    }

    ~TestSuiteRentFixture() {
        delete testaddress;
        delete testvehicle;
        delete testclient;
        delete testclient2;
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {
        Rent r(testId, testclient, testvehicle, pt::not_a_date_time);
        BOOST_TEST(testId == r.getId());
        BOOST_TEST(testclient == r.getClient());
        BOOST_TEST(testvehicle == r.getVehicle());
        BOOST_TEST(testclient->getCurrentRents() == to_string(r.getId())+ " "); //sprawdza czy przypisanie z konstruktora Rent dziala
        BOOST_TEST(testvehicle->isRented() == true); //sprawdza czy pole Vehicle::rented == true gdy powstalo wypozyczenie
    }

    BOOST_AUTO_TEST_CASE(ClientgetCurrentRents) {
        Rent r(testId, testclient, testvehicle, pt::not_a_date_time);
        BOOST_TEST(testclient->getCurrentRents() == to_string(r.getId())+ " ");
    }

    BOOST_AUTO_TEST_CASE(ClientsetCurrentRents) {
        Rent r(testId, testclient, testvehicle, pt::not_a_date_time);
        Rent r2(testId, testclient2, testvehicle, pt::not_a_date_time);
        testclient->setCurrentRents(&r2);
        BOOST_TEST(testclient->getCurrentRents() == to_string(r.getId())+ " "+ to_string(r.getId())+ " ");
    }

BOOST_AUTO_TEST_SUITE_END()