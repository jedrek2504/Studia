#ifndef rentClass
#define rentClass
#include <iostream>
#include "client.h"
#include "vehicle.h"
#include <boost/date_time.hpp>

class Client; // trzeba tak zrobic z jakiegos powodu

using namespace std;

namespace pt = boost::posix_time;

class Rent
{
    unsigned int id;
    Client *client;
    Vehicle *vehicle;
    pt::ptime beginTime;
    pt::ptime endTime;

public:

    Rent(const unsigned int &id, Client *client, Vehicle *vehicle, pt::ptime BeginTime);

    //settery
    void setId(unsigned int id);
    void setClient(Client *client);
    void setVehicle(Vehicle *vehicle);

    //settery czasu
    void setBeginTime(const pt::ptime &beginTime);
    void setEndTime(const pt::ptime &endTime);

    //gettery
    const unsigned int &getId() const;
    Client *getClient() const;
    Vehicle *getVehicle() const;

    //gettery czasu
    const pt::ptime &getBeginTime() const;
    const pt::ptime &getEndTime() const;

    string getRentInfo(); //zwraca wszystkie informacje o wypozyczeniu : id + dane klienta z addressem + dane samochodu
    unsigned int getRentDays() const; //zwraca ilosc dni wypozyczenia
    void endRent(); //metoda odpowiadajaca za zakonczenie wypozyczenia
};
#endif