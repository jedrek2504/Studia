#include <boost/test/unit_test.hpp>
#include <Regal.h>
#include <Ksiazka.h>
#include <Czasopismo.h>


BOOST_AUTO_TEST_SUITE(RejestrPojazdowTest)

    BOOST_AUTO_TEST_CASE(DodajPojazdDoRejestruTest) {
    Regal_ptr regal(new Regal(4));
    Element_ptr ksiazka1(new Ksiazka("Tren1", "Jan Kochanowski", 2));
    Element_ptr ksiazka2(new Ksiazka("Tren2", "Jan Kochanowski", 2));
    Element_ptr czasopismo(new Czasopismo("Deadpool", 1));
    BOOST_TEST_REQUIRE(regal->odloz(ksiazka1) == true);
    BOOST_TEST_REQUIRE(regal->odloz(ksiazka2) == true);
    BOOST_TEST_REQUIRE(regal->odloz(czasopismo) == false);
    BOOST_TEST_REQUIRE(regal->pobierzLiczbeElementow() == 2);
    BOOST_TEST_REQUIRE(regal->pobierzZajeteMiejsce() == 4);
    regal->toString();
    }

    BOOST_AUTO_TEST_CASE(UsunPojazdZRejestruTest) {
    Regal_ptr regal(new Regal(6));
    Element_ptr ksiazka1(new Ksiazka("Tren1", "Jan Kochanowski", 2));
    Element_ptr ksiazka2(new Ksiazka("Tren2", "Jan Kochanowski", 2));
    Element_ptr czasopismo1(new Czasopismo("Deadpool", 1));
    Element_ptr czasopismo2(new Czasopismo("Deadpool", 1));
    regal->odloz(ksiazka1);
    regal->odloz(ksiazka2);
    regal->odloz(czasopismo1);
    regal->odloz(czasopismo2);
    regal->toString();
    BOOST_TEST_REQUIRE(regal->pobierzLiczbeElementow() == 4);
    BOOST_TEST_REQUIRE(regal->pobierzZajeteMiejsce() == 6);
    regal->usun(ksiazka2);
    BOOST_TEST_REQUIRE(regal->pobierzLiczbeElementow() == 3);
    BOOST_TEST_REQUIRE(regal->pobierzZajeteMiejsce() == 4);
    regal->toString();

    }

BOOST_AUTO_TEST_SUITE_END()
