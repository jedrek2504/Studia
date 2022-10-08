#include <boost/test/unit_test.hpp>

#include "model/TicketType.h"
#include "model/typedefs.h"

BOOST_AUTO_TEST_SUITE(TestSuiteTicketType)

    BOOST_AUTO_TEST_CASE(GetInfoTest) {
        TicketType_ptr ticketType = std::make_shared<NormalTicket>();
        BOOST_TEST(ticketType->getInfo() == "normalny");

        ticketType = std::make_shared<DiscountedTicket>();
        ticketType->setDiscountType(child);
        BOOST_TEST(ticketType->getInfo() == "ulgowy , Typ znizki: dziecieca.");

        ticketType = std::make_shared<DiscountedTicket>();
        ticketType->setDiscountType(student);
        BOOST_TEST(ticketType->getInfo() == "ulgowy , Typ znizki: studencka.");

        ticketType = std::make_shared<DiscountedTicket>();
        ticketType->setDiscountType(rentist);
        BOOST_TEST(ticketType->getInfo() == "ulgowy , Typ znizki: emerycka.");
    }

    BOOST_AUTO_TEST_CASE(getRealCostTest) {
        TicketType_ptr ticketType = std::make_shared<NormalTicket>();
        BOOST_TEST(ticketType->getRealCost(100) == 100);

        ticketType = std::make_shared<DiscountedTicket>();

        ticketType->setDiscountType(child);
        BOOST_TEST(ticketType->getRealCost(100) == 50);

        ticketType->setDiscountType(student);
        BOOST_TEST(ticketType->getRealCost(100) == 70);

        ticketType->setDiscountType(rentist);
        BOOST_TEST(ticketType->getRealCost(100) == 80);


    }

BOOST_AUTO_TEST_SUITE_END()