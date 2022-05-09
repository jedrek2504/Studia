#include <boost/test/unit_test.hpp>
#include <iostream>
#include "Rack.h"
#include "Macierz.h"
#include "Serwer.h"
#include "Polka.h"

BOOST_AUTO_TEST_SUITE(BasicModelTestSuite)

    BOOST_AUTO_TEST_CASE(TworzeniePolekTest) {
        Serwer s1("s1", 100);
        BOOST_REQUIRE_EQUAL(s1.getMocCalkowita(), 100);
        BOOST_REQUIRE_EQUAL(s1.obliczWydzielanaMoc(), 100);
        Macierz m1("m1", 48, 2);
        BOOST_REQUIRE_EQUAL(m1.getMocDysku(), 48);
        BOOST_REQUIRE_EQUAL(m1.getLiczbaDyskow(), 2);
        BOOST_REQUIRE_EQUAL(m1.obliczWydzielanaMoc(), 96);
    }

    BOOST_AUTO_TEST_CASE(TworzenieRackuTest) {
        Rack rack(100);
        BOOST_REQUIRE_EQUAL(rack.obliczLiczbePolek(), 0);
        BOOST_REQUIRE_EQUAL(rack.obliczLacznaMocPolek(), 0);
    }

BOOST_AUTO_TEST_SUITE_END()
