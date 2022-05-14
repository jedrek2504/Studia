#include <boost/test/unit_test.hpp>

#include "Template.h"

BOOST_AUTO_TEST_SUITE(TemplateTest)

BOOST_AUTO_TEST_CASE(firstTest_localObject_defaultToString) {
        Template temp;
        BOOST_CHECK_EQUAL(temp.toString(), "template");
}

BOOST_AUTO_TEST_CASE(secondTest_localObject_defaultToString) {
        Template temp;
        BOOST_CHECK_EQUAL(temp.toString(), "template");
}

BOOST_AUTO_TEST_SUITE_END()
