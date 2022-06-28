#ifndef MOVIE_H
#define MOVIE_H
#include "iostream"
#include <boost/date_time.hpp>

class Movie{

    int id;
    std::string title;
    std::string genre;
    boost::posix_time::ptime beginTime; //pole ustawia sie na lokalny czas podczas tworzenia obiektu Movie
    boost::posix_time::ptime endTime; //pole ustawia sie na lokalny czas podczas wywolania metody setEndTime()
    bool archive;

public:

    Movie(int id, const std::string &title, const std::string &genre);

    virtual ~Movie();

    //getters:
    int getId() const;

    const std::string &getTitle() const;

    const std::string &getGenre() const;

    const boost::posix_time::ptime &getBeginTime() const;

    const boost::posix_time::ptime &getEndTime() const;

    bool isArchive() const;

    //setters:
    void setTitle(const std::string &title);

    void setGenre(const std::string &genre);

    void setBeginTime(const boost::posix_time::ptime &beginTime);

    void setArchive(bool archive);

    //other methods:
    void setEndTime(); //konczy film, jest wywolywana gdy korzystamy z TicketManager::endFilm()

    int getDurationInMin() const; //po zakonczeniu filmu zwraca ile trwal (w minutach)

    std::string getInfo() const; //zwraca lancuch zawierajacy informacje o filmie
};
#endif //MOVIE_H