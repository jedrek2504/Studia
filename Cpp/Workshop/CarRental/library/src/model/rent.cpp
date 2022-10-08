#include "model/client.h"
#include "model/vehicle.h"
#include "model/rent.h"

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

Rent::Rent(const unsigned int &ID, Client *c, Vehicle *v, pt::ptime BeginTime)
{
    id = ID;
    client = c;
    vehicle = v;
    //beginTime = BeginTime != pt::not_a_date_time ? BeginTime : pt::second_clock::local_time(); //nwm jeszcze co to robi kaza na grupie tak zrobic
    this->client->setCurrentRents(this); // this-> wazne w chuj to jest w konstruktorach
    this->vehicle->setRented(true);

    //sprawdzamy tutaj czy pole beginTime jest "puste" w przeciwnym razie sie program zesra:
    if(this->getBeginTime() == pt::not_a_date_time){
        this->setBeginTime(pt::second_clock::local_time());
    }
    else return;

}

const unsigned int &Rent::getId() const {
    return id;
}

Client *Rent::getClient() const {
    return client;
}

Vehicle *Rent::getVehicle() const {
    return vehicle;
}

const pt::ptime &Rent::getBeginTime() const {
    return beginTime;
}

const pt::ptime &Rent::getEndTime() const {
    return endTime;
}

void Rent::setId(unsigned int ID) {
    id = ID;
}

void Rent::setClient(Client *c) {
    client = c;
}

void Rent::setVehicle(Vehicle *v) {
    vehicle = v;
}

void Rent::setBeginTime(const pt::ptime &bT) {
    Rent::beginTime = bT;
}

void Rent::setEndTime(const pt::ptime &eT) {
    Rent::endTime = eT;
}

string Rent::getRentInfo()
{
    string StringId = to_string(id);

    //ponizej sposob zapisania okresu wypozyczenia jako string
    pt::time_period period(this->getBeginTime(), this->getEndTime());
    std::stringstream temp1;
    temp1 << this->getBeginTime();
    string temp1ToString = temp1.str();
    std::stringstream temp2;
    temp2 << this->getEndTime();
    string temp2ToString = temp2.str();

    string chain = "----------------INFORMACJE O WYPOZYCZENIU----------------";
    chain += "\nId: " + StringId + "\nKlient: " + client->getClientInfo() + "\nPojazd: " + vehicle->getVehicleInfo()+ "\n\tPoczatek: "+ temp1ToString + "\n\tKoniec:   "+ temp2ToString;
    chain += "\n---------------------------------------------------------";
    return chain;
}

void Rent::endRent()
{
    if(this->getEndTime() == pt::not_a_date_time)
    {
        if(this->getEndTime()>this->getBeginTime()) this->setEndTime(pt::second_clock::local_time());
        else this->setEndTime(this->getBeginTime());
    }
    else return;
}

unsigned int Rent::getRentDays() const
{
    if(this->getEndTime() != pt::not_a_date_time) //sprawdza czy wypozyczenie sie zakonczylo, w przeciwnym wypadku zwraca 0
    {
        pt::time_period period(this->getBeginTime(), this->getEndTime());

        if(period.length().minutes() <= 1 && period.length().hours() == 0) //anulowane wypozyczenie
        {
            return 0;
        }
        else return (period.length().hours()/24)+1; //jak dodamy 1 to sie zgadza -> bruh xd
    }
    else return 0;
}




