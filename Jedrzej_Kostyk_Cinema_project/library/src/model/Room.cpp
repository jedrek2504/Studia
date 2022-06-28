#include "model/Room.h"
#include "exceptions/ParameterException.h"

using namespace std;

Room::Room(int roomNumber, int noOfSeats) : roomNumber(roomNumber), noOfSeats(noOfSeats) {
    this->setNoOfAvailableSeats(getNoOfSeats());
    if (roomNumber <= 0) { throw ParameterException("roomNumber has to be greater than 0!"); }
    if (noOfSeats <= 0) { throw ParameterException("noOfSeats has to be greater than 0!"); }

}

Room::~Room() = default;

//getters
int Room::getNoOfSeats() const {
    return noOfSeats;
}

int Room::getRoomNumber() const {
    return roomNumber;
}

int Room::getNoOfAvailableSeats() const {
    return noOfAvailableSeats;
}

//setters
void Room::setNoOfAvailableSeats(int noOfAvailableSeats) {
    if(noOfAvailableSeats >= 0 && noOfAvailableSeats <= Room::noOfSeats) {
        Room::noOfAvailableSeats = noOfAvailableSeats;
    }
    else throw ParameterException("Number of available seats has to be greater than 0!");
}

//other methods
void Room::freeSeats() {
    setNoOfAvailableSeats(getNoOfSeats());
}

bool Room::isFull() const {
    if(getNoOfAvailableSeats() == 0) return true;
    else return false;
}



