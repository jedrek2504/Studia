#include <boost/test/unit_test.hpp>
#include "Pociag.h"
#include "Pasazerski.h"
#include "Towarowy.h"

BOOST_AUTO_TEST_SUITE(BasicModelTestSuite)

    BOOST_AUTO_TEST_CASE(TworzenieWagonowTest) {
        Towarowy towarowy(100,20);
        BOOST_REQUIRE_EQUAL(towarowy.getMasaDopuszczalna(), 100);
        BOOST_REQUIRE_EQUAL(towarowy.getPojemnoscSkrzyni(), 20);
        Pasazerski pasazerski(50, 100);
        BOOST_REQUIRE_EQUAL(pasazerski.getMasaDopuszczalna(), 50);
        BOOST_REQUIRE_EQUAL(pasazerski.getLiczbaPasazerow(), 100);
    }

    BOOST_AUTO_TEST_CASE(TworzeniePociaguTest) {
        Pociag_ptr pociag(new Pociag(100));
        BOOST_REQUIRE_EQUAL(pociag->pobierzLiczbeWagonow(), 0);
        BOOST_REQUIRE_EQUAL(pociag->pobierzLacznaMaseDopuszczalnaWagonow(), 0);
        BOOST_REQUIRE_CLOSE(pociag->pobierzSredniaMaseDopuszczalnaWagonow(), 0.0, 0.0000001);
    }

BOOST_AUTO_TEST_SUITE_END()
