#include <boost/test/unit_test.hpp>
#include "Rack.h"
#include "Macierz.h"
#include "Serwer.h"

BOOST_AUTO_TEST_SUITE(RackTest)

    BOOST_AUTO_TEST_CASE(DodajPolkeDoRackuTest) {
        std::shared_ptr<Rack> rack = std::make_shared<Rack>(222);
        std::shared_ptr<Polka> M1 = std::make_shared<Macierz>("M1", 2, 50);
        std::shared_ptr<Polka> S1 = std::make_shared<Serwer>("S1", 100);
        std::shared_ptr<Polka> S2 = std::make_shared<Serwer>("S1", 100);
        BOOST_REQUIRE_EQUAL(rack->dodajPolke(M1), true);
        BOOST_REQUIRE_EQUAL(rack->dodajPolke(S1),true);
        BOOST_REQUIRE_EQUAL(rack->dodajPolke(S2), false);
        BOOST_REQUIRE_EQUAL(rack->obliczLiczbePolek(), 2);
        BOOST_REQUIRE_EQUAL(rack->obliczLacznaMocPolek(), 200);
    }

    BOOST_AUTO_TEST_CASE(UsunPolkeZRackuTest) {
        std::shared_ptr<Rack> rack = std::make_shared<Rack>(333);
        std::shared_ptr<Polka> M1 = std::make_shared<Macierz>("M1", 1, 100);
        std::shared_ptr<Polka> M2 = std::make_shared<Macierz>("M2", 2, 50);
        std::shared_ptr<Polka> S1 = std::make_shared<Serwer>("S1", 100);
        BOOST_REQUIRE_EQUAL(rack->dodajPolke(M1), true);
        BOOST_REQUIRE_EQUAL(rack->dodajPolke(M2), true);
        BOOST_REQUIRE_EQUAL(rack->dodajPolke(S1), true);
        BOOST_REQUIRE_EQUAL(rack->usunPolke(M1), true);
        BOOST_REQUIRE_EQUAL(rack->obliczLiczbePolek(), 2);
        BOOST_REQUIRE_EQUAL(rack->obliczLacznaMocPolek(), 200);
    }

BOOST_AUTO_TEST_SUITE_END()
