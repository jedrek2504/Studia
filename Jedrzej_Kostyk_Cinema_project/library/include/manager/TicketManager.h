#ifndef TICKETMANAGER_H
#define TICKETMANAGER_H

#include "model/typedefs.h"
#include <boost/date_time.hpp>
#include <boost/uuid/uuid.hpp>

class TicketManager {

    TicketRepository_ptr ticketRepository;

public:

    explicit TicketManager(const TicketRepository_ptr &ticketRepository);

    virtual ~TicketManager();

    // Tworzy objekt ticket i zwraca na niego wskaźnik. Jeśli movie nie wystepuje w naszym projekcie metoda zwraca nullptr
    Ticket_ptr registerTicket(const float &baseCost, const Client_ptr &client, const Movie_ptr &movie,
                              const Room_ptr& room);

    // ustawia pole isArchive obiektu na true
    void unregisterTicket(const Ticket_ptr& ticket);

    // jeśli movie nie zostanie znaleziony, zwrócony zostanie nullptr
    Ticket_ptr getTicket(const boost::uuids::uuid &ticketId) const;

    // zwraca informacje o wszystkich obiektach w repozytorium
    std::string getAllTicketsReport() const;

    //wywouluje metody: Movie::setEndTime, Room::freeSeats(), Ticket::setArchive(true), TicketManager::unregiserTicket()-> dla wszystkich biletow zapisanych na danyc film
    void endFilm(const Movie_ptr& movie, boost::posix_time::ptime endTime=boost::date_time::not_a_date_time);

    Ticket_ptr findTicket(const TicketPredicate& ticketPredicate);

};

#endif //TICKETMANAGER_H
