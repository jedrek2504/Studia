#include <iostream>
#include "model/client.h"
#include "model/address.h"
#include <vector>
#include "model/rent.h"

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

int main()
{
    pt::ptime empty = pt::not_a_date_time;
    cout << empty << endl;
    pt::ptime now = pt::second_clock::local_time();
    cout << now << endl;
    pt::ptime then = pt::ptime(gr::date(2015,5,13),pt::hours(9)+pt::minutes(25));
    cout << then << endl;
    pt::time_period period(then, now);
    cout << period << endl;
    cout << period.length() << endl;
    cout << period.length().hours() << endl;
    cout << period.length().minutes() << endl;
    cout << (then>now) << endl;
    cout << (then<=now) << endl;

    // konwersja ptime na string z użyciem stringstream
    std::stringstream ss;
    ss << now;
    string s = ss.str();
    cout << s << endl;

    cout<<endl<<endl<<"EKSPERYMENT"<<endl;
    Vehicle *testvehicle = new Vehicle("testPlateNumber", 69);
    Address* testaddress = new Address("London", "Accacia Avenue", "22");
    Client* testclient = new Client("Jon", "Arbuckle", "0123456789", testaddress);

    Rent r(12, testclient, testvehicle, pt::not_a_date_time);
    r.setBeginTime(pt::ptime(gr::date(2015,5,13),pt::hours(9)+pt::minutes(25)));
    r.setEndTime(pt::ptime(gr::date(2015,5,14),pt::hours(9)+pt::minutes(25)));
    pt::time_period periodMoj(r.getBeginTime(), r.getEndTime());

    cout<<periodMoj<<endl;
    cout << periodMoj.length().hours() << endl;
    cout << periodMoj.length().minutes() << endl;
    cout<<r.getRentDays()<<endl;
    cout<<r.getRentInfo()<<endl;

    return 0;
}