//
// Created by student on 12.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/Movie.h"
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

struct TestSuiteMovieFixture {
    const int testId = 2137420;
    const std::string testTitle = "Stachu Jones: Magnaci i Czarodzieje";
    const std::string testGenre = "Fantasy, Comedy";
    const int testId2 = 1691488;
    const std::string testTitle2 = "Morbius 2: It's morbin' time";
    const std::string testGenre2 = "Sci-Fi, Action";
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteMovie, TestSuiteMovieFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest) {

        Movie movie(testId, testTitle, testGenre);
        BOOST_TEST(movie.getId() == testId);
        BOOST_TEST(movie.getTitle() == testTitle);
        BOOST_TEST(movie.getGenre() == testGenre);
    }

    BOOST_AUTO_TEST_CASE(ContructorTestExceptions) {
        BOOST_REQUIRE_THROW(Movie movie(0, testTitle, testGenre), std::logic_error);
        BOOST_REQUIRE_THROW(Movie movie(-44, testTitle, testGenre), std::logic_error);
        BOOST_REQUIRE_THROW(Movie movie(testId, "", testGenre), std::logic_error);
        BOOST_REQUIRE_THROW(Movie movie(testId, testTitle, ""), std::logic_error);
    }

    BOOST_AUTO_TEST_CASE(GetInfoTest) {
        Movie movie(testId, testTitle, testGenre);
        std::string chainStr;
        chainStr = movie.getInfo();
        std::stringstream chain;

        chain << "Film: " << testTitle << ", Typ filmu: " << testGenre << ", godzina rozpoczecia:" << movie.getBeginTime()
              << ", STATUS: w trakcie odtwarzania.";

        BOOST_TEST(chainStr == chain.str() + " Film nie jest archiwalny;" );

    }

BOOST_AUTO_TEST_SUITE_END()