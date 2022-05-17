#include <boost/test/unit_test.hpp>



#include <BoatRental.h>
#include <RowBoat.h>
#include <SailBoat.h>


BOOST_AUTO_TEST_SUITE(RejestrPojazdowTest)

    BOOST_AUTO_TEST_CASE(DodajPojazdDoRejestruTest) {
/*
        Glowna_ptr glowna(new BoatRental( ));
        Abstrakcyjna_ptr pochodna1(new Pochodna1( ));
        Abstrakcyjna_ptr pochodna2(new SailBoat( ));

        BOOST_TEST_REQUIRE(glowna->dodaj(pochodna1) == true);
        BOOST_TEST_REQUIRE(glowna->dodaj(pochodna2) == false);

        BOOST_TEST_REQUIRE(glowna->pobierzLiczbe() == );
        BOOST_TEST_REQUIRE(glowna->pobierzLaczna() == );

        std::cout<<glowna->toString();
*/
    }

    BOOST_AUTO_TEST_CASE(UsunPojazdZRejestruTest) {
/*
        Glowna_ptr glowna(new BoatRental( ));
        Abstrakcyjna_ptr pochodna1(new Pochodna1( ));
        Abstrakcyjna_ptr pochodna2(new SailBoat( ));

        glowna->dodaj(pochodna1);

        BOOST_TEST_REQUIRE(glowna->pobierzLiczbe() == );
        BOOST_TEST_REQUIRE(glowna->pobierzLaczna() == );

        std::cout<<glowna->toString();

        glowna->usun(pochodna1);

        BOOST_TEST_REQUIRE(glowna->pobierzLiczbe() == );
        BOOST_TEST_REQUIRE(glowna->pobierzLaczna() == );

        std::cout<<glowna->toString();
*/
    }

BOOST_AUTO_TEST_SUITE_END()
