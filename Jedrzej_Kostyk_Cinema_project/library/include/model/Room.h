#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <memory>

class Room{

    int roomNumber;
    int noOfSeats;
    int noOfAvailableSeats;

public:

    Room(int roomNumber, int noOfSeats);

    virtual ~Room();

    //getters
    int getNoOfSeats() const;

    int getRoomNumber() const;

    int getNoOfAvailableSeats() const;

    //setters:
    void setNoOfAvailableSeats(int noOfAvailableSeats);

    //other methods:
    void freeSeats(); //zwalnia wszystkie siedzenia w sali.

    bool isFull() const; //zwraca wartosc logiczna w zaleznosci od tego czy sala jest pelna czy nie.

};

#endif //ROOM_H