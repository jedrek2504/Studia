#include <boost/test/unit_test.hpp>

#include "Statek.h"
#include "Luzny.h"
#include "Paletowy.h"

namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(StatekTest)

    BOOST_AUTO_TEST_CASE(DodajLadunekDoStatkuTest) {
        Statek_ptr Sta(new Statek(46));
        Luzny_ptr L1(new Luzny("L1", 15));
        Luzny_ptr L2(new Luzny("L2", 15));
        Paletowy_ptr P1(new Paletowy("P1", 1, 15));
        Paletowy_ptr P2(new Paletowy("P2", 1, 15));

        BOOST_CHECK_EQUAL(Sta->dodajLadunek(L1), true);
        BOOST_CHECK_EQUAL(Sta->dodajLadunek(L2), true);
        BOOST_CHECK_EQUAL(Sta->dodajLadunek(P1), true);
        BOOST_CHECK_EQUAL(Sta->dodajLadunek(P2), false);

        BOOST_CHECK_EQUAL(Sta->pobierzLiczbeLadunkow(), 3);
        BOOST_CHECK_EQUAL(Sta->pobierzLacznaMaseLadunkow(), 45);

        BOOST_CHECK_CLOSE(Sta->pobierzSredniaMaseLadunkow(), 15, 0.0000001);
    }

    BOOST_AUTO_TEST_CASE(UsunLadunekZeStatkuTest) {

    }

BOOST_AUTO_TEST_SUITE_END()
