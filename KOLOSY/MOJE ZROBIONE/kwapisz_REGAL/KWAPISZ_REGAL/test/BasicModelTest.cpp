#include <boost/test/unit_test.hpp>
#include "Regal.hpp"
#include "Czasopismo.hpp"
#include "Ksiazka.hpp"

BOOST_AUTO_TEST_SUITE(BasicModelTestSuite)

    BOOST_AUTO_TEST_CASE(TworzenieElementowTest) {
        Ksiazka ksiazka("Treny", "Kochanowski", 100);
        BOOST_REQUIRE_EQUAL(ksiazka.getAutor(), "Kochanowski");
        BOOST_REQUIRE_EQUAL(ksiazka.getTytul(), "Treny");
        BOOST_REQUIRE_EQUAL(ksiazka.getRozmiar(), 100);
        Czasopismo czasopismo("Młody Technik", 10);
        BOOST_REQUIRE_EQUAL(czasopismo.getNazwa(), "Młody Technik");
        BOOST_REQUIRE_EQUAL(czasopismo.getRozmiar(), 10);
    }

    BOOST_AUTO_TEST_CASE(TworzenieRegaluTest) {
        Regal regal(100);
        BOOST_REQUIRE_EQUAL(regal.pobierzZajeteMiejsce(), 0);
        BOOST_REQUIRE_EQUAL(regal.pobierzLiczbeElementow(), 0);

        Czasopismo *czasopismo = new Czasopismo("Młoady Technik", 100);
        regal.odloz(czasopismo);

        BOOST_REQUIRE_EQUAL(regal.pobierzZajeteMiejsce(), 100);
        BOOST_REQUIRE_EQUAL(regal.pobierzLiczbeElementow(), 1);
        BOOST_TEST_MESSAGE(regal.toString());
    }

BOOST_AUTO_TEST_SUITE_END()
