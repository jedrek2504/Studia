#include <boost/test/unit_test.hpp>
#include "model/address.h"

struct TestSuiteAddressFixture {
    const std::string testCity = "Aleksandrow";
    const std::string testStreet = "Pilsudskiego";
    const std::string testNumber = "72";
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteAddress, TestSuiteAddressFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {

        Address a(testCity, testStreet, testNumber);
        BOOST_TEST(testCity == a.getCity());
        BOOST_TEST(testStreet == a.getStreet());
        BOOST_TEST(testNumber == a.getNumber());
    }

    BOOST_AUTO_TEST_CASE(AddressgetCity) {
        Address a(testCity, testStreet, testNumber);
        BOOST_TEST(a.getCity() == testCity);
    }

    BOOST_AUTO_TEST_CASE(AddressgetStreet) {
        Address a(testCity, testStreet, testNumber);
        BOOST_TEST(a.getStreet() == testStreet);
    }

    BOOST_AUTO_TEST_CASE(AddressgetNumber) {
        Address a(testCity, testStreet, testNumber);
        BOOST_TEST(a.getNumber() == testNumber);
    }

    BOOST_AUTO_TEST_CASE(AddresssetCity) {
        Address a(testCity, testStreet, testNumber);
        a.setCity("dupa");
        BOOST_TEST(a.getCity() == "dupa");
    }

    BOOST_AUTO_TEST_CASE(AddresssetStreet) {
        Address a(testCity, testStreet, testNumber);
        a.setStreet("");
        BOOST_TEST(a.getStreet() == testStreet); //sprawdza czy zosatje to samo jak sie nic nie wpisze
    }

    BOOST_AUTO_TEST_CASE(AddresssetNumber) {
        Address a(testCity, testStreet, testNumber);
        a.setNumber("123512351355");
        BOOST_TEST(a.getNumber() == "123512351355");
    }

BOOST_AUTO_TEST_SUITE_END()

