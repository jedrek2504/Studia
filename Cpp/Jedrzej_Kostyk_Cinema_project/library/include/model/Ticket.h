#ifndef TICKET_H
#define TICKET_H
#include <iostream>
#include <boost/uuid/uuid.hpp>
#include "typedefs.h"

class Ticket {

    const boost::uuids::uuid Id;
    float baseCost;
    Client_ptr client;
    Movie_ptr movie;
    Room_ptr room;
    bool archive;
    TicketType_ptr ticketType;

public:

    Ticket(const boost::uuids::uuid &id, float baseCost, const Client_ptr &client, const Movie_ptr &movie,
           const Room_ptr &room); //w konstruktorze jest ustalona znizka oraz mozliwosc zakupu biletu.

    virtual ~Ticket();

    //getters:
    const boost::uuids::uuid &getId() const;

    float getBaseCost() const;

    bool isArchive() const;

    const Client_ptr &getClient() const;

    const Movie_ptr &getMovie() const;

    const Room_ptr &getRoom() const;

    const TicketType_ptr &getTicketType() const;

    //setters:

    void setMovie(const Movie_ptr &movie);

    void setRoom(const Room_ptr &room);

    void setBaseCost(float baseCost);

    void setArchive(bool archive);

    void setTicketType(const TicketType_ptr &ticketType);

    //other methods:
    bool isAvailable();

    std::string getInfo(); //zwraca informacje o bilecie w tym : klient, na jaki film , w ktorej sali, typ biletu, typ znizki

};

#endif //TICKET_H
