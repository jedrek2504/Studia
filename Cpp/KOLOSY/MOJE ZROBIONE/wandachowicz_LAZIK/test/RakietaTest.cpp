//
// Created by student on 14.05.2022.
//
#include <boost/test/unit_test.hpp>
#include <iostream>
#include "RakietaKosmiczna.h"
#include "Satelita.h"
#include "LazikMarsjanski.h"

BOOST_AUTO_TEST_SUITE(RakietaTest)

    BOOST_AUTO_TEST_CASE(ZaladowanieDoRakietyTEST) {
        RakietaKosmiczna_ptr rakieta(new RakietaKosmiczna(4));
        Element_ptr lazik1(new LazikMarsjanski(2 , "LAZIKUS1" , "DiKarpio1"));
        Element_ptr lazik2(new LazikMarsjanski(2 , "LAZIKUS2" , "DiKarpio2"));
        Element_ptr satelita(new Satelita(1 , "Wojtyla"));

        BOOST_TEST_REQUIRE(rakieta->zaladuj(lazik1)== true);
        BOOST_TEST_REQUIRE(rakieta->zaladuj(lazik2)== true);
        BOOST_TEST_REQUIRE(rakieta->zaladuj(satelita)== false);
        BOOST_TEST_REQUIRE(rakieta->pobierzLiczbeElementow() == 2);
        BOOST_TEST_REQUIRE(rakieta->pobierzZajeteMiejsce() == 4);
        std::cout<<rakieta->toString();
    }

    BOOST_AUTO_TEST_CASE(UsuniecieZrakietyTEST) {
        RakietaKosmiczna_ptr rakieta(new RakietaKosmiczna(6));
        Element_ptr lazik1(new LazikMarsjanski(2 , "LAZIKUS1" , "DiKarpio1"));
        Element_ptr lazik2(new LazikMarsjanski(2 , "LAZIKUS2" , "DiKarpio2"));
        Element_ptr satelita1(new Satelita(1 , "Wojtyla1"));
        Element_ptr satelita2(new Satelita(1 , "Wojtyla2"));
        rakieta->zaladuj(lazik1);
        rakieta->zaladuj(lazik2);
        rakieta->zaladuj(satelita1);
        rakieta->zaladuj(satelita2);
        BOOST_TEST_REQUIRE(rakieta->pobierzLiczbeElementow() == 4);
        BOOST_TEST_REQUIRE(rakieta->pobierzZajeteMiejsce() == 6);
        std::cout<<rakieta->toString();
        rakieta->usun(lazik2);
        BOOST_TEST_REQUIRE(rakieta->pobierzLiczbeElementow() == 3);
        BOOST_TEST_REQUIRE(rakieta->pobierzZajeteMiejsce() == 4);
        std::cout<<rakieta->toString();

    }

BOOST_AUTO_TEST_SUITE_END()
