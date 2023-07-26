#include <boost/uuid/random_generator.hpp>
#include "manager/TicketManager.h"
#include "model/Ticket.h"
#include "model/Repository.h"
#include "model/Movie.h"
#include "model/Room.h"
#include "exceptions/ParameterException.h"

TicketManager::TicketManager(const TicketRepository_ptr &ticketRepository) : ticketRepository(ticketRepository) {
    if (ticketRepository == nullptr) { throw ParameterException("Cannot create ticketRepository without repository!"); }
}

TicketManager::~TicketManager() = default;

Ticket_ptr TicketManager::registerTicket(const float &baseCost, const Client_ptr &client, const Movie_ptr &movie,
                                         const Room_ptr& room) {
    boost::uuids::random_generator gen;
    Ticket_ptr newTicket = std::make_shared<Ticket>(gen(), baseCost, client, movie, room);
    ticketRepository->add(newTicket);
    return newTicket;
}

void TicketManager::unregisterTicket(const Ticket_ptr& ticket) {
    ticket->setArchive(true);
}

void TicketManager::endFilm(const Movie_ptr& movie, boost::posix_time::ptime endTime) {

    movie->setArchive(true); //film staje sie archiwalny
    movie->setEndTime(); //ustawiamy end time podanego filmu na aktualny

    TicketPredicate predicate = [movie](const Ticket_ptr& ptr) { //jezeli znajdziemy ticket zarejestroweany na dany film to go zwracamy
        return ptr->getMovie() == movie;
    };

    ticketRepository->find(predicate)->getRoom()->freeSeats(); //bierzemy room zwrocenego wczesniej ticketu i zwalniamy wszystkie miejsca w roomie

    for(int i=0 ; i<ticketRepository->findAll(predicate).size() ; i++){
        ticketRepository->findAll(predicate)[i]->setArchive(true); //kazdy z biletow na dany film zostaje uznany za archiwalny
    }
}

Ticket_ptr TicketManager::findTicket(const TicketPredicate& ticketPredicate) {
    return ticketRepository->find(ticketPredicate);
}

std::string TicketManager::getAllTicketsReport() const {
    return ticketRepository->report();
}

Ticket_ptr TicketManager::getTicket(const boost::uuids::uuid &ticketId) const {
    TicketPredicate predicate = [ticketId](const Ticket_ptr& ptr) {
        return ptr->getId() == ticketId;
    };
    return ticketRepository->find(predicate);
}



