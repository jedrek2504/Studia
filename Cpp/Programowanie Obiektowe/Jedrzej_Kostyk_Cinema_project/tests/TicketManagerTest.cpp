#include <boost/test/unit_test.hpp>
#include "manager/TicketManager.h"
#include "model/Repository.h"
#include "model/Ticket.h"
#include "model/Client.h"
#include "model/Room.h"
#include "model/Movie.h"
#include <boost/uuid/uuid_generators.hpp>

struct TestSuiteTicketManagerFixture {
    //client
    const std::string testFirstName = "Andrzej";
    const std::string testLastName = "Wodecki";
    const int testAge = 55;
    const std::string testEmailAddress = "huncwot@o2.pl";
    //room
    const unsigned int testRoomNumber = 12;
    const unsigned int testNoOfSeats = 40;
    //movie
    const int testId = 1;
    const std::string testTitle = "Piraci z Karaibow: Na krańcu świata";
    const std::string testGenre = "Akcja";

    const float testBaseCost = 100.0;

    TicketRepository_ptr testTicketRepository;
    Client_ptr testClient;
    Movie_ptr testMovie;
    Room_ptr testRoom;

    TestSuiteTicketManagerFixture() {
        testTicketRepository = std::make_shared<Repository<Ticket_ptr>>();
        testClient = std::make_shared<Client>(testFirstName, testLastName, testAge, testEmailAddress);
        testRoom = std::make_shared<Room>( testRoomNumber, testNoOfSeats);
        testMovie = std::make_shared<Movie>(testId, testTitle, testGenre);
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteTicketManager, TestSuiteTicketManagerFixture)

    BOOST_AUTO_TEST_CASE(ContructorException) {
        BOOST_REQUIRE_THROW(new TicketManager(nullptr), std::logic_error);
    }

    BOOST_AUTO_TEST_CASE(RegisterTicketTest) {
        TicketManager tManager(testTicketRepository);
        Ticket_ptr testTicket = tManager.registerTicket(testBaseCost, testClient,testMovie , testRoom);

        BOOST_TEST(testTicket == tManager.getTicket(testTicket->getId()));
    }

    BOOST_AUTO_TEST_CASE(GetTicketTest) {
        TicketManager tManager(testTicketRepository);

        Ticket_ptr testTicket = tManager.registerTicket(testBaseCost, testClient,testMovie , testRoom);

        BOOST_TEST(tManager.getTicket(testTicket->getId()) == testTicket);
    }

    BOOST_AUTO_TEST_CASE(UnregisterClientTest) {
        TicketManager tManager(testTicketRepository);


        Ticket_ptr testTicket = tManager.registerTicket(testBaseCost, testClient,testMovie , testRoom);
        tManager.unregisterTicket(testTicket);

        BOOST_TEST(tManager.getTicket(testTicket->getId())->isArchive() == true);
    }

    BOOST_AUTO_TEST_CASE(EndFilmTest) {
        TicketManager tManager(testTicketRepository);

        BOOST_TEST(testRoom->getNoOfAvailableSeats() == 40);
        Ticket_ptr testTicket = tManager.registerTicket(testBaseCost, testClient,testMovie , testRoom);
        BOOST_TEST(testTicket->isArchive() == false);
        BOOST_TEST(testRoom->getNoOfAvailableSeats() == 39);
        tManager.endFilm(testMovie);
        BOOST_TEST(testRoom->getNoOfAvailableSeats() == 40);
        BOOST_TEST(testTicket->isArchive() == true);
    }


BOOST_AUTO_TEST_SUITE_END()
