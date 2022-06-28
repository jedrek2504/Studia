#include "model/Movie.h"
#include <boost/date_time.hpp>
#include "exceptions/ParameterException.h"

using namespace std;

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

Movie::Movie(int id, const string &title, const string &genre)
        : id(id), title(title), genre(genre){

    //exceptions
    if (id <= 0) {throw ParameterException("Invalid ID (has to be greater than 0)!"); }
    if (title.empty()) {throw ParameterException("Invalid title (can't be empty)!"); }
    if (genre.empty()) {throw ParameterException("Invalid genre (can't be empty)!"); }

    this->setArchive(false);

    this->setBeginTime(pt::second_clock::local_time()); //ustawiamy poczatkowy czas na bieżący

    endTime = boost::posix_time::not_a_date_time; //ustawiamy czas zakonczenia na not_a_date_time (zostanie zmieniony przy wywolaniu setEndTime())

}

Movie::~Movie() = default;

//getters
int Movie::getId() const {
    return id;
}

const std::string &Movie::getTitle() const {
    return title;
}

const std::string &Movie::getGenre() const {
    return genre;
}

const boost::posix_time::ptime &Movie::getBeginTime() const {
    return beginTime;
}

const boost::posix_time::ptime &Movie::getEndTime() const {
    return endTime;
}

bool Movie::isArchive() const {
    return archive;
}

//setters
void Movie::setEndTime() {
    if (getEndTime() == boost::posix_time::not_a_date_time) {
        endTime = boost::posix_time::second_clock::local_time();
    }
}

void Movie::setArchive(bool archive) {
    Movie::archive = archive;
}

void Movie::setBeginTime(const boost::posix_time::ptime &beginTime) {
    Movie::beginTime = beginTime;
}

void Movie::setTitle(const string &title) {
    Movie::title = title;
}

void Movie::setGenre(const string &genre) {
    Movie::genre = genre;
}

//other methods
int Movie::getDurationInMin() const {
    pt::time_period period(getBeginTime(), getEndTime());
    return period.length().minutes();
}

std::string Movie::getInfo() const {
    std::stringstream chain;

    if(getEndTime() == pt::not_a_date_time)
    {
        chain<<"Film: "<<getTitle()<<", Typ filmu: "<<getGenre()<<", godzina rozpoczecia:"<<getBeginTime()<<", STATUS: w trakcie odtwarzania.";
    }
    else
    {
        chain<<"Film: "<<getTitle()<<", Typ filmu: "<<getGenre()<<", godzina rozpoczecia: "<<getBeginTime()<<", godzina zakonczenia: "<<getEndTime()<<", Czas trwania: "<<getDurationInMin()<<" min."; //jezeli film juz sie zakonczyl to uwzgledniamy ile trwal metoda etDurationInMin()
    }

    if(isArchive()) {   // if zeby bylo widac czy dane movie zawarte sa w archiwum
        return chain.str() + " Film jest archiwalny.";
    }
    return chain.str() + " Film nie jest archiwalny;";
}

