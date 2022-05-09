#include <boost/test/unit_test.hpp>

#include "Template.h"

#include "budynek.h"
#include "biuro.h"
#include "mieszkanie.h"
#include "lokal.h"

BOOST_AUTO_TEST_SUITE(TemplateTest)

BOOST_AUTO_TEST_CASE(firstTest_localObject_defaultToString) {
        Template temp;
        BOOST_CHECK_EQUAL(temp.toString(), "template");
}

BOOST_AUTO_TEST_CASE(secondTest_localObject_defaultToString) {
        Template temp;
        BOOST_CHECK_EQUAL(temp.toString(), "template");
}

BOOST_AUTO_TEST_CASE(Testcase1_localObject_defaultToString) {

            Budynek_ptr budynek(new Budynek());

            Mieszkanie_ptr m1(new Mieszkanie(60,15.0));
            Mieszkanie_ptr m2(new Mieszkanie(90,14.0));
            Mieszkanie_ptr m3(new Mieszkanie(40,10.0));

            Biuro_ptr b1(new Biuro(20,20.0,140.0));
            Biuro_ptr b2(new Biuro(90,30.0,200.0));

            budynek->dodaj_lokal(m1);
            budynek->dodaj_lokal(m2);
            budynek->dodaj_lokal(m3);
            budynek->dodaj_lokal(b1);
            budynek->dodaj_lokal(b2);

            double calkowity = budynek->czynsz_calkowity();

            BOOST_CHECK_EQUAL(calkowity, 6000 );

    }

BOOST_AUTO_TEST_SUITE_END()
