#include <boost/test/unit_test.hpp>
#include "model/client.h"
#include "model/address.h"

struct TestSuiteClientFixture {
    const std::string testFirstName = "Jon";
    const std::string testLastName = "Arbuckle";
    const std::string testPersonalID = "0123456789";
    Address *testaddress1;
    Address *testaddress2;

    TestSuiteClientFixture() {
        testaddress1 = new Address("London", "Accacia Avenue", "22");
        testaddress2 = new Address("London", "Rue Morgue", "13");
    }

    ~TestSuiteClientFixture() {
        delete testaddress1;
        delete testaddress2;
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {

        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(testFirstName == c.getFirstName());
        BOOST_TEST(testLastName == c.getLastName());
        BOOST_TEST(testPersonalID == c.getPersonalId());
        BOOST_TEST(testaddress1 == c.getAddress());
    }

    BOOST_AUTO_TEST_CASE(ClientgetFirstNameTest) {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(c.getFirstName() == testFirstName);
    }

    BOOST_AUTO_TEST_CASE(ClientgetLastNameTest) {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(c.getLastName() == testLastName);
    }

    BOOST_AUTO_TEST_CASE(ClientgetPerssonalIDTest) {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(c.getPersonalId() == testPersonalID);
    }

    BOOST_AUTO_TEST_CASE(ClientgetAddress) {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(c.getAddress() == testaddress1);
    }

    BOOST_AUTO_TEST_CASE(ClientsetFirstNameTest) {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setFirstName("dupa");
        BOOST_TEST(c.getFirstName() == "dupa");
    }

    BOOST_AUTO_TEST_CASE(ClientsetLastNameTest) {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setLastName("Kowalski");
        BOOST_TEST(c.getLastName() == "Kowalski");
    }

    BOOST_AUTO_TEST_CASE(ClientsetPersonalIDTest) {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setPersonalId("123512351355");
        BOOST_TEST(c.getPersonalId() == "123512351355");
    }

    BOOST_AUTO_TEST_CASE(ClientsetAddress) {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setAddress(testaddress2);
        BOOST_TEST( c.getAddress() == testaddress2);
    }

BOOST_AUTO_TEST_SUITE_END()

//warsztat2:
//odp 1.1 - warunek nie jest spelniony; zostala wykonana 1 asercja
//odp 1.2 - zostaly wykonane 2 asercje ; 1wsza asercja ma negatywny wynik ;
//odp 1-2 : require wymaga zeby sie spelnial warunek i juz dalej nie patrzy jak jest niespelniony ; check sprawdza i jezeli jest niespelniony to i tak idzie dalej
//odp 1.3 - test zdany - 1 asercja sie wykonala ; pierwsza asercja zakonczyla sie pozytywnym wynikiem ; caly test jest zakonczony pozytywnie ;
//odp 1-3: WARN - sprawdza ktore sie zesralo i jak sie zesralo to passuje i mowi ze test jest pozytywny
//odp 1.4 - domyslnie jest wykonywany typ CHECK
//odp 1.5 - jak zmienilismy tolerancje na 0.1 to odnioslo zamierzony skutek