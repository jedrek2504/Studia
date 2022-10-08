#include <boost/test/unit_test.hpp>

#include "model/Room.h"

struct TestSuiteRoomFixture {
    const int testRoomNumber = 1;
    const int testNoOfSeats = 134;
    const int testRoomNumber2 = 2;
    const int testNoOfSeats2 = 286;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRoom, TestSuiteRoomFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest) {
        Room room(testRoomNumber, testNoOfSeats);

        BOOST_TEST(room.getRoomNumber() == testRoomNumber);
        BOOST_TEST(room.getNoOfSeats() == testNoOfSeats);
        BOOST_TEST(room.getNoOfAvailableSeats() == testNoOfSeats);
    }

    BOOST_AUTO_TEST_CASE(ContructorTestExceptions) {
        BOOST_REQUIRE_THROW(Room room(0, testNoOfSeats), std::logic_error);
        BOOST_REQUIRE_THROW(Room room(testRoomNumber, 0), std::logic_error);
        BOOST_REQUIRE_THROW(Room room(-56, testNoOfSeats), std::logic_error);
        BOOST_REQUIRE_THROW(Room room(testRoomNumber, -56), std::logic_error);
}

    BOOST_AUTO_TEST_CASE(SettersTest) {
    Room room(testRoomNumber,testNoOfSeats);

    room.setNoOfAvailableSeats(testNoOfSeats - 1); // idk jak to inaczej
        BOOST_TEST(room.getNoOfAvailableSeats() == testNoOfSeats - 1);
    }

    BOOST_AUTO_TEST_CASE(freeSeatsTest) {
    Room room(testRoomNumber, testNoOfSeats);
    room.setNoOfAvailableSeats(40);
    room.freeSeats();
        BOOST_TEST(room.getNoOfAvailableSeats() == room.getNoOfSeats());
}

    BOOST_AUTO_TEST_CASE(isFullTest) {
        Room room(testRoomNumber, testNoOfSeats);
        room.setNoOfAvailableSeats(0);
        BOOST_TEST(room.isFull());
    }







BOOST_AUTO_TEST_SUITE_END()
