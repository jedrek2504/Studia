//
// Created by student on 24.05.2022.
//

#include <boost/test/unit_test.hpp>

#include "model/Client.h"
#include "model/typedefs.h"

//Client_ptr testClient(new Client("Mariusz", "Świątecki", 43, "mar.sw@gmail.com"));
struct TestSuiteClientFixture {
    const std::string testFirstName = "Jan";
    const std::string testLastName = "Nowak";
    const int testAge = 40;
    const std::string testEmailAdress = "jannwk@gmail.com";
    const std::string testFirstName2 = "Janusz";
    const std::string testLastName2 = "Kowalczyk";
    const int testAge2 = 23;
    const std::string testEmailAdress2 = "jan00sh@gmail.com";
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)


BOOST_AUTO_TEST_CASE(ContructorTest){
    Client client(testFirstName, testLastName, testAge, testEmailAdress);

        BOOST_TEST(client.getFirstName() == testFirstName);
        BOOST_TEST(client.getLastName() == testLastName);
        BOOST_TEST(client.getAge() == testAge);
        BOOST_TEST(client.getEmailAddress() == testEmailAdress);
        BOOST_TEST(!client.isArchive());
}

BOOST_AUTO_TEST_CASE(ContructorTestExceptions){
        Client client(testFirstName,testLastName,testAge,testEmailAdress);
        BOOST_REQUIRE_THROW(Client client("", testLastName, testAge, testEmailAdress), std::logic_error);
        BOOST_REQUIRE_THROW(Client client(testFirstName, "", testAge, testEmailAdress), std::logic_error);
        BOOST_REQUIRE_THROW(Client client(testFirstName, testLastName, -18, testEmailAdress), std::logic_error);
        BOOST_REQUIRE_THROW(Client client(testFirstName, testLastName, 0, testEmailAdress), std::logic_error);
        BOOST_REQUIRE_THROW(Client client(testFirstName, testLastName, testAge, ""), std::logic_error);
        //BOOST_TEST(!client.getAge() <= 0);
}

    BOOST_AUTO_TEST_CASE(SettersTest) {
        Client client(testFirstName, testLastName, testAge, testEmailAdress);

        client.setFirstName(testFirstName2);
        BOOST_TEST(client.getFirstName() == testFirstName2);
        //client.setFirstName("");
        //BOOST_TEST(client.getFirstName() == testFirstName2);

        client.setLastName(testLastName2);
        BOOST_TEST(client.getLastName() == testLastName2);
        //client.setLastName("");
        //BOOST_TEST(client.getLastName() == testLastName2);

        client.setAge(testAge2);
        BOOST_TEST(client.getAge() == testAge2);
        //client.setAge(-8);                          //TODO prawdopodobnie pozwoli ustawic -8. W ktorym miejscu zabronic?
        //BOOST_TEST(client.getAge() == testAge);
    }

    BOOST_AUTO_TEST_CASE(GetInfoTest) {
        Client client(testFirstName, testLastName, testAge, testEmailAdress);
        std::stringstream chain;
        chain << "Imie: " << testFirstName << ", nazwisko: " << testLastName << ", wiek:" << testAge << ", adres email: " << testEmailAdress << ".";
        BOOST_TEST(client.getInfo() == chain.str() + " Klient nie jest archiwalny.");

}

    BOOST_AUTO_TEST_CASE(ArchiveTest) {
        Client client(testFirstName, testLastName, testAge, testEmailAdress);

        client.setArchive(false);

        BOOST_TEST(!client.isArchive()); // dac "!" przed czy nie?
    }

BOOST_AUTO_TEST_SUITE_END()