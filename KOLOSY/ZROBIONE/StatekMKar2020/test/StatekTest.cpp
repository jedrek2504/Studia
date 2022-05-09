#include <boost/test/unit_test.hpp>
#include <Statek.hpp>
#include <Paletowy.hpp>
#include <Luzny.hpp>

namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(StatekTest)

    BOOST_AUTO_TEST_CASE(DodajLadunekDoStatkuTest) {
        Statek ship(359);
        ladunekPtr luzny1(new Luzny("Luzny1", 100));
        ladunekPtr luzny2(new Luzny("Luzny2", 100));
        ladunekPtr paletowy1(new Paletowy("Paletowy1", 10, 10));
        ladunekPtr paletowy2(new Paletowy("Paletowy2", 10, 10));
        BOOST_REQUIRE_EQUAL(ship.dodajLadunek(luzny1),true);
        BOOST_REQUIRE_EQUAL(ship.dodajLadunek(luzny2),true);
        BOOST_REQUIRE_EQUAL(ship.dodajLadunek(paletowy1),true);
        BOOST_REQUIRE_EQUAL(ship.dodajLadunek(paletowy2),false);
        BOOST_REQUIRE_EQUAL(ship.pobierzLiczbeLadunkow(),3);
        BOOST_REQUIRE_EQUAL(ship.pobierzLacznaMaseLadunkow(),300);
        BOOST_REQUIRE_EQUAL(ship.pobierzSredniaMaseLadunkow(),100);
    }

    BOOST_AUTO_TEST_CASE(UsunLadunekZeStatkuTest) {
        Statek ship(259);
    ladunekPtr luzny1(new Luzny("Luzny1", 44));
    ladunekPtr luzny2(new Luzny("Luzny2", 66));
    ladunekPtr paletowy1(new Paletowy("Paletowy1", 11, 8));
    BOOST_REQUIRE_EQUAL(ship.dodajLadunek(luzny1),true);
    BOOST_REQUIRE_EQUAL(ship.dodajLadunek(luzny2),true);
    BOOST_REQUIRE_EQUAL(ship.dodajLadunek(paletowy1),true);
    BOOST_REQUIRE_EQUAL(ship.usunLadunek(paletowy1),true);
    BOOST_REQUIRE_EQUAL(ship.pobierzLiczbeLadunkow(),2);
    BOOST_REQUIRE_EQUAL(ship.pobierzLacznaMaseLadunkow(),110);
    BOOST_REQUIRE_EQUAL(ship.pobierzSredniaMaseLadunkow(),55);

    }

BOOST_AUTO_TEST_SUITE_END()
