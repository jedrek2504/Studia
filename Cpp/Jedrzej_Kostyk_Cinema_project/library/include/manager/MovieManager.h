#ifndef MOVIEMANAGER_H
#define MOVIEMANAGER_H

#include "model/typedefs.h"
#include <string>

class MovieManager{

    MovieRepository_ptr movieRepository;

public:

    explicit MovieManager(const MovieRepository_ptr &movieRepository);

    virtual ~MovieManager();

    // Tworzy obiekt movie i zwraca na niego wskaźnik. Jeśli movie jest już stworzony zamienia jego pole isArchive na false
    Movie_ptr registerMovie(int id, const std::string &title, const std::string &genre);

    // ustawia pole isArchive obiektu na true
    void unregisterMovie(const Movie_ptr &movie);

    // zwraca wskaznik filmu o odpowiadajacym id
    Movie_ptr getMovie(const int &movieId) const;

    // zwraca informacje o wszystkich filmach w repozytorium
    std::string getAllMoviesReport() const;
};
#endif //MOVIEMANAGER_H