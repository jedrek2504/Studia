#include <boost/test/unit_test.hpp>
#include "Pociag.h"
#include "Towarowy.h"
#include "Pasazerski.h"


BOOST_AUTO_TEST_SUITE(PociagTest)

    BOOST_AUTO_TEST_CASE(DodajWagonDoPociaguTest) {
    Pociag_ptr pociag(new Pociag(333));
    Wagon_ptr t1(new Towarowy(100, 100));
    Wagon_ptr t2(new Towarowy(100, 100));
    Wagon_ptr p1(new Pasazerski(100, 100));
    Wagon_ptr p2(new Pasazerski(100, 100));
    /*NWM JAK TO WDROZYC WHATEVER XD
    pociag->dodajWagon(t1);
    pociag->dodajWagon(t2);
    pociag->dodajWagon(p1);
    pociag->dodajWagon(p2);
     */
    BOOST_TEST_REQUIRE(pociag->dodajWagon(t1)== true);
    BOOST_TEST_REQUIRE(pociag->dodajWagon(t2)== true);
    BOOST_TEST_REQUIRE(pociag->dodajWagon(p1)== true);
    BOOST_TEST_REQUIRE(pociag->dodajWagon(p2)== false);
    BOOST_TEST_REQUIRE(pociag->pobierzLiczbeWagonow()==  3);
    BOOST_TEST_REQUIRE(pociag->pobierzLacznaMaseDopuszczalnaWagonow()== 300);
    BOOST_TEST_REQUIRE(pociag->pobierzSredniaMaseDopuszczalnaWagonow()== 100);


    }

    BOOST_AUTO_TEST_CASE(UsunWagonZPociaguTest) {
        Pociag_ptr pociag(new Pociag(333));
        Wagon_ptr t1(new Towarowy(100, 100));
        Wagon_ptr t2(new Towarowy(100, 100));
        Wagon_ptr p1(new Pasazerski(100, 100));
        BOOST_TEST_REQUIRE(pociag->dodajWagon(t1)== true);
        BOOST_TEST_REQUIRE(pociag->dodajWagon(t2)== true);
        BOOST_TEST_REQUIRE(pociag->dodajWagon(p1)== true);
        pociag->usunWagon(t2);
        BOOST_TEST_REQUIRE(pociag->pobierzLiczbeWagonow()==  2);
        BOOST_TEST_REQUIRE(pociag->pobierzLacznaMaseDopuszczalnaWagonow()== 200);
        BOOST_TEST_REQUIRE(pociag->pobierzSredniaMaseDopuszczalnaWagonow()== 100);
    }

BOOST_AUTO_TEST_SUITE_END()
