#include <boost/test/unit_test.hpp>

#include "Jablko.h"
#include "Sliwka.h"
#include "Skrzynka.h"

BOOST_AUTO_TEST_SUITE(SkrzynkaTest)

    BOOST_AUTO_TEST_CASE(DodajOwocDoSkrzynkiTest, *boost::unit_test::tolerance(0.00001)) {
        Skrzynka_ptr skrzynka(new Skrzynka(2));
        Owoc_ptr jablko1(new Jablko(1 , 10));
        Owoc_ptr jablko2(new Jablko(1 , 10 ));
        Owoc_ptr sliwka(new Sliwka(0.1 , 10));
        BOOST_TEST_REQUIRE(skrzynka->wlozOwoc(jablko1) == true);
        BOOST_TEST_REQUIRE(skrzynka->wlozOwoc(sliwka) == true);
        BOOST_TEST_REQUIRE(skrzynka->wlozOwoc(jablko2) == false);
        BOOST_TEST_REQUIRE(skrzynka->pobierzMasaCalkowita() == 1.1);
        BOOST_TEST_REQUIRE(skrzynka->pobierzCenaCalkowita() == 11); // to sprawdza ile nalezy juz zaplacic a nie laczne cene za kg

        std::cout<<skrzynka->toString();
    }

    BOOST_AUTO_TEST_CASE(UsunOwocZeSkrzynkiTest, *boost::unit_test::tolerance(0.00001)) {
        Skrzynka_ptr skrzynka(new Skrzynka(100));
        Owoc_ptr jablko1(new Jablko(1 , 10));
        Owoc_ptr jablko2(new Jablko(1 , 10 ));
        Owoc_ptr sliwka(new Sliwka(0.1 , 10));
        skrzynka->wlozOwoc(jablko1);
        skrzynka->wlozOwoc(jablko2);
        skrzynka->wlozOwoc(sliwka);
        BOOST_TEST_REQUIRE(skrzynka->pobierzMasaCalkowita() == 2.1);
        BOOST_TEST_REQUIRE(skrzynka->pobierzCenaCalkowita() == 21);
        BOOST_TEST_REQUIRE(skrzynka->usunOwoc(jablko2) == true);
        BOOST_TEST_REQUIRE(skrzynka->pobierzMasaCalkowita() == 1.1);
        BOOST_TEST_REQUIRE(skrzynka->pobierzCenaCalkowita() == 11);
    }

BOOST_AUTO_TEST_SUITE_END()
