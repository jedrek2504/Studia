#include <boost/test/unit_test.hpp>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>

#include "Opakowanie.h"
#include "Skrzynia.h"
#include "Beczka.h"
#include "Magazyn.h"

using namespace std;
using namespace kolokwium;

typedef std::shared_ptr<Opakowanie> OpakowaniePtr;

BOOST_AUTO_TEST_SUITE(NauczycielSuite)

BOOST_AUTO_TEST_CASE(Nauczyciel1Test)
{
//    Skrzynia s(2342, 1, 2, 3);
//    BOOST_REQUIRE_EQUAL(s.getIdentyfikator(), 2342);
//    BOOST_REQUIRE_EQUAL(s.getWysokosc(), 1);
//    BOOST_REQUIRE_EQUAL(s.getSzerokosc(), 2);
//    BOOST_REQUIRE_EQUAL(s.getGlebokosc(), 3);
//
//    Beczka b(9391, 4, 5);
//    BOOST_REQUIRE_EQUAL(b.getIdentyfikator(), 9391);
//    BOOST_REQUIRE_EQUAL(b.getPromien(), 4);
//    BOOST_REQUIRE_EQUAL(b.getWysokosc(), 5);
//
//    Magazyn m(400);
//    BOOST_REQUIRE_EQUAL(m.getPojemnosc(), 400);
}

BOOST_AUTO_TEST_CASE(Nauczyciel2Test)
{
//    OpakowaniePtr s = make_shared<Skrzynia>(2342, 1, 2, 3);
//    BOOST_REQUIRE_EQUAL(s->objetosc(), 6);
//    BOOST_REQUIRE_EQUAL(s->opis(), "[2342] - skrzynia o wymiarach 1x2x3");
//
//    OpakowaniePtr b = make_shared<Beczka>(9391, 4, 5);
//    BOOST_REQUIRE_EQUAL(b->objetosc(), 40);
//    BOOST_REQUIRE_EQUAL(b->opis(), "[9391] - beczka o promieniu 4 i wysokosci 5");
}

BOOST_AUTO_TEST_CASE(Nauczyciel3Test)
{
//    OpakowaniePtr s = make_shared<Skrzynia>(2342, 1, 2, 3);
//    OpakowaniePtr b = make_shared<Beczka>(9391, 4, 5);
//    Magazyn m(30);
//    BOOST_REQUIRE_EQUAL(m.dostepnaPojemnosc(), 30);
//    bool status;
//    status = m.wstaw(s);
//    BOOST_REQUIRE(status);
//    BOOST_REQUIRE_EQUAL(m.dostepnaPojemnosc(), 24);
//    BOOST_REQUIRE_EQUAL(m.liczbaOpakowan(), 1);
//    status = m.wstaw(b);
//    BOOST_REQUIRE(!status);
//    BOOST_REQUIRE_EQUAL(m.dostepnaPojemnosc(), 24);
//    BOOST_REQUIRE_EQUAL(m.liczbaOpakowan(), 1);
//
//    OpakowaniePtr o = m.opakowanie(0);
//    BOOST_REQUIRE_EQUAL(o, s);
//
//    ostringstream sout;
//    sout << "1. [2342] - skrzynia o wymiarach 1x2x3" << endl;
//    sout << "Liczba opakowan: 1" << endl;
//    sout << "Dostepna pojemnosc: 24" << endl;
//    BOOST_REQUIRE_EQUAL(sout.str(), m.opis());
}

BOOST_AUTO_TEST_SUITE_END()
