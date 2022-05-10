#include <boost/test/unit_test.hpp>
#include <Pociag.h>
#include <Towarowy.h>
#include <Pasazerski.h>


BOOST_AUTO_TEST_SUITE(PociagTest)

    BOOST_AUTO_TEST_CASE(DodajWagonDoPociaguTest) {
    Pociag_ptr pociag(new Pociag(333));
    Wagon_ptr towarowy(new Towarowy(100,30));
    Wagon_ptr towarowy2(new Towarowy(100,30));
    Wagon_ptr pasazerski (new Pasazerski(100, 60));
    Wagon_ptr pasazerski2 (new Pasazerski(100, 60));
    BOOST_REQUIRE_EQUAL(pociag->dodajWagon(towarowy),true);
    BOOST_REQUIRE_EQUAL(pociag->dodajWagon(towarowy2),true);
    BOOST_REQUIRE_EQUAL(pociag->dodajWagon(pasazerski),true);
    BOOST_REQUIRE_EQUAL(pociag->dodajWagon(pasazerski2),false);
    BOOST_REQUIRE_EQUAL(pociag->pobierzLiczbeWagonow(),3);
    BOOST_REQUIRE_EQUAL(pociag->pobierzLacznaMaseDopuszczalnaWagonow(),300);
    BOOST_REQUIRE_EQUAL(pociag->pobierzSredniaMaseDopuszczalnaWagonow(),100);
    }

    BOOST_AUTO_TEST_CASE(UsunWagonZPociaguTest) {
    Pociag_ptr pociag(new Pociag(333));
    Wagon_ptr towarowy(new Towarowy(100,30));
    Wagon_ptr towarowy2(new Towarowy(100,30));
    Wagon_ptr pasazerski (new Pasazerski(100, 60));
    BOOST_REQUIRE_EQUAL(pociag->dodajWagon(towarowy),true);
    BOOST_REQUIRE_EQUAL(pociag->dodajWagon(towarowy2),true);
    BOOST_REQUIRE_EQUAL(pociag->dodajWagon(pasazerski),true);
    pociag->usunWagon(pasazerski);
    BOOST_REQUIRE_EQUAL(pociag->pobierzLiczbeWagonow(),2);
    BOOST_REQUIRE_EQUAL(pociag->pobierzLacznaMaseDopuszczalnaWagonow(),200);
    BOOST_REQUIRE_EQUAL(pociag->pobierzSredniaMaseDopuszczalnaWagonow(),100);
    }

BOOST_AUTO_TEST_SUITE_END()
