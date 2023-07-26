#include <boost/test/unit_test.hpp>
#include "manager/MovieManager.h"
#include "model/Repository.h"
#include "model/Movie.h"

struct TestSuiteMovieManagerFixture {
    const int testId = 1;
    const int testId2 = 2;
    const std::string testTitle = "Piraci z Karaibow: Na krańcu świata";
    const std::string testTitle2 = "Hobbit: Niezwykła podróż";
    const std::string testGenre = "Akcja";
    const std::string testGenre2 = "Przygodowy";
    MovieRepository_ptr testMovieRepository;
    Movie_ptr testMovie;
    Movie_ptr testMovie2;
    TestSuiteMovieManagerFixture() {
        testMovie = std::make_shared<Movie>(testId, testTitle, testGenre);
        testMovie2 = std::make_shared<Movie>(testId2, testTitle2, testGenre2);
        testMovieRepository = std::make_shared<Repository<Movie_ptr>>();
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteMovieManager, TestSuiteMovieManagerFixture)

    BOOST_AUTO_TEST_CASE(ContructorException) {
        BOOST_REQUIRE_THROW(new MovieManager(nullptr), std::logic_error);
    }

    BOOST_AUTO_TEST_CASE(RegisterMovieTest) {
        MovieManager mManager(testMovieRepository);

        Movie_ptr testMovie = mManager.registerMovie(testId, testTitle, testGenre);

        BOOST_TEST(testMovie == mManager.getMovie(testId));
    }

    BOOST_AUTO_TEST_CASE(RegisterMovieTestTheSameID) {
        MovieManager mManager(testMovieRepository);

        Movie_ptr testMovie1 = mManager.registerMovie(testId, testTitle, testGenre);
        Movie_ptr testMovie2 = mManager.registerMovie(testId2, testTitle2, testGenre2);

        BOOST_TEST_REQUIRE(testMovie1 = testMovie2);
        BOOST_TEST(testMovie1->getId() == testId2);
        BOOST_TEST(testMovie1->getTitle() == testTitle2);
        BOOST_TEST(testMovie1->getGenre() == testGenre2);
        BOOST_TEST(testMovie1->isArchive() == false);
    }

    BOOST_AUTO_TEST_CASE(GetMovieTest) {
        MovieManager mManager(testMovieRepository);

        Movie_ptr testMovie = mManager.registerMovie(testId, testTitle, testGenre);

        BOOST_TEST(mManager.getMovie(testId) == testMovie);
    }

    BOOST_AUTO_TEST_CASE(UnregisterMovieTest) {
        MovieManager mManager(testMovieRepository);

        Movie_ptr movie = mManager.registerMovie(testId, testTitle, testGenre);
        mManager.unregisterMovie(movie);

        BOOST_TEST(mManager.getMovie(testId)->isArchive());
    }

BOOST_AUTO_TEST_SUITE_END()