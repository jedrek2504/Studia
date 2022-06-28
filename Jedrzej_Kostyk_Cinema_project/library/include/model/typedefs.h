#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <memory>
#include <functional>
#include "TicketType.h"

// model
class Client;
class Ticket;
class Movie;
class Room;
class TicketType;
template<class T>
class Repository;

// ticket types
class NormalTicket;
class DiscountedTicket;

// managers
class ClientManager;
class TicketManager;
class MovieManager;

// model smart pointers
typedef std::shared_ptr<Client> Client_ptr;
typedef std::shared_ptr<Ticket> Ticket_ptr;
typedef std::shared_ptr<Room> Room_ptr;
typedef std::shared_ptr<Movie> Movie_ptr;
typedef std::shared_ptr<TicketType> TicketType_ptr;
typedef std::shared_ptr<DiscountType> DiscountType_ptr;

// repositories smart pointers
typedef std::shared_ptr<Repository<Client_ptr>> ClientRepository_ptr;
typedef std::shared_ptr<Repository<Ticket_ptr>> TicketRepository_ptr;
typedef std::shared_ptr<Repository<Movie_ptr>> MovieRepository_ptr;

// predicates
typedef std::function<bool(Client_ptr)> ClientPredicate;
typedef std::function<bool(Ticket_ptr)> TicketPredicate;
typedef std::function<bool(Movie_ptr)> MoviePredicate;

// managars smart pointers
typedef std::shared_ptr<ClientManager> ClientManager_ptr;
typedef std::shared_ptr<TicketManager> TicketManager_ptr;
typedef std::shared_ptr<MovieManager> MovieManager_ptr;



#endif //TYPEDEFS_H
