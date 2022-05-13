#include <boost/test/unit_test.hpp>



#include <Glowna.h>
#include <Pochodna1.h>
#include <Pochodna2.h>


BOOST_AUTO_TEST_SUITE(RejestrPojazdowTest)

    BOOST_AUTO_TEST_CASE(DodajPojazdDoRejestruTest) {

        Glowna_ptr glowna(new Glowna( ));
        Abstrakcyjna_ptr pochodna1(new Pochodna1( ));
        Abstrakcyjna_ptr pochodna2(new Pochodna2( ));

        BOOST_TEST_REQUIRE(glowna->dodaj(pochodna1) == true);
        BOOST_TEST_REQUIRE(glowna->dodaj(pochodna2) == false);

        BOOST_TEST_REQUIRE(glowna->pobierzLiczbe() == );
        BOOST_TEST_REQUIRE(glowna->pobierzLaczna() == );

        std::cout<<glowna->toString();

    }

    BOOST_AUTO_TEST_CASE(UsunPojazdZRejestruTest) {

        Glowna_ptr glowna(new Glowna( ));
        Abstrakcyjna_ptr pochodna1(new Pochodna1( ));
        Abstrakcyjna_ptr pochodna2(new Pochodna2( ));

        glowna->dodaj(pochodna1);

        BOOST_TEST_REQUIRE(glowna->pobierzLiczbe() == );
        BOOST_TEST_REQUIRE(glowna->pobierzLaczna() == );

        std::cout<<glowna->toString();

        glowna->usun(pochodna1);

        BOOST_TEST_REQUIRE(glowna->pobierzLiczbe() == );
        BOOST_TEST_REQUIRE(glowna->pobierzLaczna() == );

        std::cout<<glowna->toString();

    }

BOOST_AUTO_TEST_SUITE_END()
