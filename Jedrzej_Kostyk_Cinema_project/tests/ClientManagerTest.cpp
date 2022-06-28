#include <boost/test/unit_test.hpp>
#include "manager/ClientManager.h"
#include "model/Repository.h"
#include "model/Client.h"

struct TestSuiteClientManagerFixture {
    const std::string testFirstName = "Andrzej";
    const std::string testFirstName2 = "Karol";
    const std::string testLastName = "Wodecki";
    const std::string testLastName2 = "Krawczyk";
    const int testAge = 55;
    const int testAge2 = 17;
    const std::string testEmailAddress = "huncwot@o2.pl";
    const std::string testEmailAddress2 = "bananatree@wp.pl";
    ClientRepository_ptr testClientRepository;
    Client_ptr testClient;
    Client_ptr testClient2;
    TestSuiteClientManagerFixture() {
        testClient = std::make_shared<Client>(testFirstName, testLastName,testAge,testEmailAddress);
        testClient2 = std::make_shared<Client>(testFirstName2, testLastName2,testAge2,testEmailAddress2);
        testClientRepository = std::make_shared<Repository<Client_ptr>>();
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientManager, TestSuiteClientManagerFixture)

    BOOST_AUTO_TEST_CASE(ContructorException) {
        BOOST_REQUIRE_THROW(new ClientManager(nullptr), std::logic_error);
    }

    BOOST_AUTO_TEST_CASE(RegisterClientTest) {
        ClientManager cManager(testClientRepository);

        Client_ptr testClient = cManager.registerClient(testFirstName, testLastName, testAge, testEmailAddress);

        BOOST_TEST(testClient == cManager.getClient(testEmailAddress));
    }

    BOOST_AUTO_TEST_CASE(RegisterClientTestTheSameID) {
        ClientManager cManager(testClientRepository);

        Client_ptr testClient1 = cManager.registerClient(testFirstName, testLastName, testAge, testEmailAddress);
        Client_ptr testClient2 = cManager.registerClient(testFirstName2, testLastName2, testAge2, testEmailAddress2);

        BOOST_TEST_REQUIRE(testClient1 = testClient2);
        BOOST_TEST(testClient1->getFirstName() == testFirstName2);
        BOOST_TEST(testClient1->getLastName() == testLastName2);
        BOOST_TEST(testClient1->getAge() == testAge2);
        BOOST_TEST(testClient1->getEmailAddress() == testEmailAddress2);
        BOOST_TEST(testClient1->isArchive() == false);
    }

    BOOST_AUTO_TEST_CASE(GetClientTest) {
        ClientManager cManager(testClientRepository);

        Client_ptr testClient = cManager.registerClient(testFirstName, testLastName, testAge, testEmailAddress);

        int size = 5;
        for (int i = 0; i < size; i++) {
            std::ostringstream sout;
            sout << "huncwot@o2.pl" << (i);
            cManager.registerClient("Janusz", "Kowalski", testAge, sout.str());
        }

        BOOST_TEST(cManager.getClient(testEmailAddress) == testClient);
    }

    BOOST_AUTO_TEST_CASE(GetClientTestNullPtr) {
        ClientManager cManager(testClientRepository);

        int size = 5;
        for (int i = 0; i < size; i++) {
            std::ostringstream sout;
            sout << "huncwot@o2.pl" << (i);
            cManager.registerClient("Janusz", "Kowalski", testAge , sout.str());
        }

        BOOST_TEST(cManager.getClient(testEmailAddress2) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(UnregisterClientTest) {
        ClientManager cManager(testClientRepository);

        Client_ptr client = cManager.registerClient(testFirstName, testLastName, testAge, testEmailAddress);
        cManager.unregisterClient(client);

        BOOST_TEST(cManager.getClient(testEmailAddress)->isArchive());
    }

BOOST_AUTO_TEST_SUITE_END()