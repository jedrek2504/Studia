#include "model/Ticket.h"
#include <boost/uuid/uuid_io.hpp>
#include "model/Client.h"
#include "model/Movie.h"
#include "model/Room.h"
#include "model/TicketType.h"
#include "exceptions/LogicException.h"
#include "exceptions/ParameterException.h"


using namespace std;

Ticket::Ticket(const boost::uuids::uuid &id, float baseCost, const Client_ptr &client, const Movie_ptr &movie,
               const Room_ptr &room) : Id(id), baseCost(baseCost), client(client), movie(movie), room(room) {

    this->setArchive(false);

    if (baseCost <= 0) {throw ParameterException("Invalid baseCost (has to be greater than 0)!"); }
    if (client == nullptr) {throw ParameterException("Invalid client (can't be empty)!"); }
    if (movie == nullptr) {throw ParameterException("Invalid movie (can't be empty)!"); }
    if (room == nullptr) {throw ParameterException("Invalid room (can't be empty)!"); }
    if (!this->isAvailable()) {throw ParameterException("No available seats left.");}

    if (isAvailable()) room->setNoOfAvailableSeats(room->getNoOfAvailableSeats() - 1);

    //ustala na jaka znizke zalapie sie nasz klient(w zaleznosci od jego wieku)
    if((client->getAge() > 0 && client->getAge() <= 10 ) || (client->getAge() >= 18 && client->getAge() <= 25) || (client->getAge() >= 63))
    {
        if(client->getAge() > 0 && client->getAge() <= 10)
        {
            setTicketType(std::make_shared<DiscountedTicket>());
            ticketType->setDiscountType(child);
            setBaseCost(ticketType->getRealCost(getBaseCost()));
        }
        if(client->getAge() >= 18 && client->getAge() <= 25 )
        {
            setTicketType(std::make_shared<DiscountedTicket>());
            ticketType->setDiscountType(student);
            setBaseCost(ticketType->getRealCost(getBaseCost()));
        }
        if(client->getAge() >= 63)
        {
            setTicketType(std::make_shared<DiscountedTicket>());
            ticketType->setDiscountType(rentist);
            setBaseCost(ticketType->getRealCost(getBaseCost()));
        }
    }
    else
    {
        setTicketType(std::make_shared<NormalTicket>());
        setBaseCost(ticketType->getRealCost(getBaseCost()));
    }
}

Ticket::~Ticket() = default;

//getters
const boost::uuids::uuid &Ticket::getId() const {
    return Id;
}

const Client_ptr &Ticket::getClient() const {
    return client;
}

const Movie_ptr &Ticket::getMovie() const {
    return movie;
}

const Room_ptr &Ticket::getRoom() const {
    return room;
}

float Ticket::getBaseCost() const {
    return baseCost;
}

bool Ticket::isArchive() const {
    return archive;
}

const TicketType_ptr &Ticket::getTicketType() const {
    return ticketType;
}

//setters
void Ticket::setBaseCost(float baseCost) {
    Ticket::baseCost = baseCost;
}

void Ticket::setArchive(bool archive) {
    Ticket::archive = archive;
}

void Ticket::setTicketType(const TicketType_ptr &ticketType) {
    Ticket::ticketType = ticketType;
}
void Ticket::setMovie(const Movie_ptr &movie) {
    Ticket::movie = movie;
}

void Ticket::setRoom(const Room_ptr &room) {
    Ticket::room = room;
}

//other methods
bool Ticket::isAvailable() {
    if(room->isFull() == false) return true;
    return false;
}

std::string Ticket::getInfo() {
    std::stringstream chain;
    chain<<"INFORMACJE O BILECIE: "<<endl;
    chain << "Id: " << getId() << endl;
    chain<<"Dane Klienta: "<<getClient()->getInfo()<<endl;
    chain<<"Dane Filmu: " <<getMovie()->getInfo()<<endl;
    chain<<"Numer sali: "<<getRoom()->getRoomNumber()<<endl;
    chain<<"Cena: "<<getBaseCost()<<" , Typ biletu: "<<ticketType->getInfo()<<endl;

    if(isArchive()) {
        return chain.str() + "bilet jest archiwalny.";
    }
    return chain.str() + "bilet nie jest archiwalny.";
}








