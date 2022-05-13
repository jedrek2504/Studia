#include <boost/test/unit_test.hpp>
#include <RejestrPojazdow.h>
#include <SamochodCiezarowy.h>
#include <SamochodOsobowy.h>


BOOST_AUTO_TEST_SUITE(RejestrPojazdowTest)
    //NIE MA POLECENIA ALE ZROBILEM COS NA RYMPAL SAMEMU

    BOOST_AUTO_TEST_CASE(DodajPojazdDoRejestruTest) {
        RejestrPojazdow_ptr rejestr(new RejestrPojazdow(2));
        Pojazd_ptr osobowka1(new SamochodOsobowy("WA1234", 4));
        Pojazd_ptr osobowka2(new SamochodOsobowy("WA4321", 4));
        Pojazd_ptr ciezarowka(new SamochodCiezarowy( "EL12345" , 1000));
        BOOST_TEST_REQUIRE(rejestr->dodajPojazd(osobowka1) == true);
        BOOST_TEST_REQUIRE(rejestr->dodajPojazd(ciezarowka) == true);
        BOOST_TEST_REQUIRE(rejestr->dodajPojazd(osobowka2) == false);
        BOOST_TEST_REQUIRE(rejestr->pobierzLiczbePojazdow() == 2);

        std::cout<<rejestr->toString();
    }

    BOOST_AUTO_TEST_CASE(UsunPojazdZRejestruTest) {
        RejestrPojazdow_ptr rejestr(new RejestrPojazdow(3));
        Pojazd_ptr osobowka1(new SamochodOsobowy("WA1234", 4));
        Pojazd_ptr osobowka2(new SamochodOsobowy("WA4321", 4));
        Pojazd_ptr ciezarowka(new SamochodCiezarowy( "EL12345" , 1000));
        rejestr->dodajPojazd(osobowka1);
        rejestr->dodajPojazd(osobowka2);
        rejestr->dodajPojazd(ciezarowka);
        BOOST_TEST_REQUIRE(rejestr->pobierzLiczbePojazdow() == 3);

        std::cout<<rejestr->toString();

        rejestr->usunPojazd(osobowka2);
        BOOST_TEST_REQUIRE(rejestr->pobierzLiczbePojazdow() == 2);

        std::cout<<rejestr->toString();
    }

BOOST_AUTO_TEST_SUITE_END()
