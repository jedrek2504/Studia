#include "model/Ticket.h"
#include "model/Client.h"
#include "model/Movie.h"
#include "model/Room.h"

#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/test/unit_test.hpp>

using namespace std;


struct TestSuiteTicketFixture {
const float testBaseCost = 30;
const float testBaseCost2 = 45.5;
Client_ptr testClient;
Client_ptr testClient2;
Movie_ptr testMovie;
Movie_ptr testMovie2;
Room_ptr testRoom;
Room_ptr testRoom2;
boost::uuids::uuid testId;
boost::uuids::uuid testId2;

    TestSuiteTicketFixture() {
        boost::uuids::random_generator gen;
        boost::uuids::random_generator gen2;
        testId = gen();
        testId2 = gen2();
        testClient = std::make_shared<Client>("Julian", "Zając", 32, "zajac@edu.p.lodz.pl");
        testRoom = std::make_shared<Room>(1, 150);
        testMovie = std::make_shared<Movie>(23424, "Cars 3", "Animation");
        testClient2 = std::make_shared<Client>("Jacek", "Zrobek", 89, "jaca@o2.pl");
        testRoom2 = std::make_shared<Room>(7, 370);
        testMovie2 = std::make_shared<Movie>(765422, "F&F vol. 18", "Action");
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteTicket, TestSuiteTicketFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest) {

    Ticket ticket(testId, testBaseCost, testClient, testMovie, testRoom);
        BOOST_TEST(ticket.getId() == testId);
        BOOST_TEST(ticket.getBaseCost() == testBaseCost);
        BOOST_TEST(ticket.getClient() == testClient);
        BOOST_TEST(ticket.getMovie() == testMovie);
        BOOST_TEST(ticket.getRoom() == testRoom);
    }

    BOOST_AUTO_TEST_CASE(ConstructorWhenNotAvailable) {
        Ticket ticket(testId, testBaseCost, testClient, testMovie, testRoom);
        BOOST_TEST(ticket.isAvailable() == true);
        testRoom->setNoOfAvailableSeats(0);
        BOOST_TEST(testRoom->getNoOfAvailableSeats() == 0);
        BOOST_TEST(ticket.isAvailable() == false);
        BOOST_REQUIRE_THROW(Ticket ticket2(testId2, testBaseCost2, testClient2, testMovie2, testRoom);, std::logic_error);
    }

        BOOST_AUTO_TEST_CASE(ContructorTestExceptions) {
        BOOST_REQUIRE_THROW(Ticket ticket(testId, testBaseCost, testClient, testMovie, nullptr);, std::logic_error);
        BOOST_REQUIRE_THROW(Ticket ticket(testId, testBaseCost, testClient, nullptr, testRoom);, std::logic_error);
        BOOST_REQUIRE_THROW(Ticket ticket(testId, testBaseCost, nullptr, testMovie, testRoom);, std::logic_error);
        BOOST_REQUIRE_THROW(Ticket ticket(testId, 0, testClient, testMovie, testRoom);, std::logic_error);
        BOOST_REQUIRE_THROW(Ticket ticket(testId, -1, testClient, testMovie, testRoom);, std::logic_error);
    }

    BOOST_AUTO_TEST_CASE(SettersTest) {
        Ticket ticket(testId, testBaseCost, testClient, testMovie, testRoom);
        ticket.setArchive(true);
        BOOST_TEST(ticket.isArchive() == true);
        ticket.setBaseCost(700);
        BOOST_TEST(ticket.getBaseCost() == 700);
        ticket.setMovie(testMovie2);
        BOOST_TEST(ticket.getMovie() == testMovie2 );
        ticket.setRoom(testRoom2);
        BOOST_TEST(ticket.getRoom() == testRoom2 );
}

    BOOST_AUTO_TEST_CASE(GetInfoTest) {
        Ticket ticket(testId, testBaseCost, testClient, testMovie, testRoom);
        std::stringstream chain;
        chain<<"INFORMACJE O BILECIE: "<<endl;
        chain << "Id: " << testId << endl;
        chain<<"Dane Klienta: "<<testClient->getInfo()<<endl;
        chain<<"Dane Filmu: " <<testMovie->getInfo()<<endl;
        chain<<"Numer sali: "<<testRoom->getRoomNumber()<<endl;
        chain<<"Cena: "<<testBaseCost<<" , Typ biletu: "<<ticket.getTicketType()->getInfo()<<endl;

        BOOST_TEST(ticket.getInfo() == chain.str() + "bilet nie jest archiwalny.");
}

    BOOST_AUTO_TEST_CASE(isAvailableTest) {
        Ticket ticket(testId, testBaseCost, testClient, testMovie, testRoom);
        BOOST_TEST(ticket.isAvailable() == true);
        ticket.getRoom()->setNoOfAvailableSeats(0);
        BOOST_TEST(!ticket.isAvailable() == true);
}

BOOST_AUTO_TEST_SUITE_END()
