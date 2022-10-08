#include <boost/test/unit_test.hpp>

#include "Jablko.h"
#include "Sliwka.h"
#include "Skrzynka.h"

BOOST_AUTO_TEST_SUITE(BasicModelTestSuite)

    BOOST_AUTO_TEST_CASE(TworzenieOwocow) {
        Sliwka sliwka(2.0, 3.0);//waga,cenaZaKilogram
        BOOST_REQUIRE_CLOSE(sliwka.getWaga(), 2.0, 0.000001);
        BOOST_REQUIRE_CLOSE(sliwka.getCenaZaKilogram(), 3.0, 0.000001);
        BOOST_REQUIRE_CLOSE(sliwka.getCena(), 6.0, 0.000001);
        BOOST_TEST_MESSAGE(sliwka.toString());
        Jablko jablko(3.0, 4.0);
        BOOST_REQUIRE_CLOSE(jablko.getWaga(), 3.0, 0.000001);
        BOOST_REQUIRE_CLOSE(jablko.getCenaZaKilogram(), 4.0, 0.000001);
        BOOST_REQUIRE_CLOSE(jablko.getCena(), 12.0, 0.000001);
        BOOST_TEST_MESSAGE(jablko.toString());
    }


    BOOST_AUTO_TEST_CASE(SkrzynkaPoUtworzeniuJestPusta) {
        Skrzynka skrzynka(2.0);//maksymalna masa w kilogramach
        BOOST_REQUIRE_CLOSE(skrzynka.pobierzMasaCalkowita(), 0.0, 0.000001);
        BOOST_REQUIRE_CLOSE(skrzynka.pobierzCenaCalkowita(), 0.0, 0.000001);
    }

    BOOST_AUTO_TEST_CASE(SkrzynkaPoDodaniuOwocuNieJestPusta) {
        Skrzynka skrzynka(2.0);//maksymalna masa w kilogramach

        Sliwka *owoc = new Sliwka(1.0, 2.0);//waga,cenaZaKilogram
        BOOST_REQUIRE(skrzynka.wlozOwoc(static_cast<Owoc_ptr>(owoc))); // korzystam z shared pointera zatem trzeba zorbic static_cast

        BOOST_REQUIRE_GT(skrzynka.pobierzMasaCalkowita(), 0.0);
        BOOST_REQUIRE_GT(skrzynka.pobierzCenaCalkowita(), 0.0);
        BOOST_TEST_MESSAGE(skrzynka.toString());
    }

BOOST_AUTO_TEST_SUITE_END()
