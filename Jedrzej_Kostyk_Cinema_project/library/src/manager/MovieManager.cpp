#include "manager/MovieManager.h"
#include "model/Repository.h"
#include "model/Movie.h"
#include "exceptions/ParameterException.h"

MovieManager::MovieManager(const MovieRepository_ptr &movieRepository) : movieRepository(movieRepository){
    if (movieRepository == nullptr) { throw ParameterException("Cannot create movieManager without repository!"); }
}

MovieManager::~MovieManager() = default;

Movie_ptr MovieManager::registerMovie(int id, const std::string &title, const std::string &genre) {
    Movie_ptr movieCheck = getMovie(id);  //sprawdzamy czy istnieje movie w repozytorium: jesli movieCheck = nullptr to go nie ma
                                                 //a jezeli jest to upewniamy sie ze dokona sie dearchiwizacja.
    if (movieCheck == nullptr) {
        Movie_ptr newMovie = std::make_shared<Movie>(id , title, genre);
        movieRepository->add(newMovie);
        return newMovie;
    } else {
        movieCheck->setArchive(false);      // gdy movie był zarchiwizowany dokonuje się dearchiwizacja

        // ustawione zostają nowe dane movie
        movieCheck->setTitle(title);
        movieCheck->setGenre(genre);

        return movieCheck;
    }
}

std::string MovieManager::getAllMoviesReport() const {
    return movieRepository->report();
}

void MovieManager::unregisterMovie(const Movie_ptr &movie) {
    if (movie == nullptr) {
        throw ParameterException("Invalid Movie_ptr!");
    }
    movie->setArchive(true);
}

Movie_ptr MovieManager::getMovie(const int &movieId) const {
    MoviePredicate predicate = [movieId](const Movie_ptr& ptr) {
        return ptr->getId() == movieId;
    };
    return movieRepository->find(predicate);
}
