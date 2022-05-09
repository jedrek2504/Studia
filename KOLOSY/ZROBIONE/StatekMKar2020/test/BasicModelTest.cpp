#include <boost/test/unit_test.hpp>
#include <Paletowy.hpp>
#include <Luzny.hpp>
#include <Statek.hpp>

namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(BasicModelTestSuite)

    BOOST_AUTO_TEST_CASE(TworzenieLadunkowTest) {
        Paletowy paleta("P1", 10, 10);
        BOOST_TEST(paleta.getMasaPalety() == 10);
        BOOST_TEST(paleta.getLiczbaPalet() == 10);
        BOOST_TEST(paleta.obliczMase() == 100);

        Luzny luzny("L1", 100);
        BOOST_TEST(luzny.getMasaLadunku() == 100);
        BOOST_TEST(luzny.obliczMase() == 100);
    }

    BOOST_AUTO_TEST_CASE(TworzenieStatkuTest) {
        Statek statek(100);
        BOOST_TEST(statek.pobierzLiczbeLadunkow() == 0);
        BOOST_TEST(statek.pobierzLacznaMaseLadunkow() == 0);
        BOOST_TEST(statek.pobierzSredniaMaseLadunkow() == 0.0, btt::tolerance(0.0000001));
    }

BOOST_AUTO_TEST_SUITE_END()
