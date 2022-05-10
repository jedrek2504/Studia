#include "Pociag.h"
#include <sstream>

using namespace std;

Pociag::Pociag(int masaMaksymalna) : masaMaksymalna(masaMaksymalna) {}

Pociag::~Pociag() {

}

int Pociag::getMasaMaksymalna() const {
    return masaMaksymalna;
}

void Pociag::setMasaMaksymalna(int masaMaksymalna) {
    Pociag::masaMaksymalna = masaMaksymalna;
}

bool Pociag::dodajWagon(Wagon_ptr wagon) {
    if(wagon->getMasaDopuszczalna()+pobierzLacznaMaseDopuszczalnaWagonow()<=getMasaMaksymalna())
    {
        wagony.push_back(wagon);
        return true;
    }
    else return false;
}

bool Pociag::usunWagon(Wagon_ptr wagon) {
    for(int i=0 ; i<wagony.size() ; i++)
    {
        if(wagony[i] == wagon)
        {
            wagony[i] = nullptr;
            wagony.erase(wagony.begin() + i);
            return true;
        }
    }
    return false;
}

int Pociag::pobierzLiczbeWagonow() {
    return wagony.size();
}

int Pociag::pobierzLacznaMaseDopuszczalnaWagonow() {
    int CalkowitaMasa=0;
    for(int i=0 ; i<wagony.size() ; i++)
        CalkowitaMasa+=wagony[i]->getMasaDopuszczalna();
    return CalkowitaMasa;
}

float Pociag::pobierzSredniaMaseDopuszczalnaWagonow() {
    if(wagony.size() != 0)
    return (float)pobierzLacznaMaseDopuszczalnaWagonow()/(float)wagony.size();
    else return 0;
}

std::string Pociag::toString() {
    stringstream chain;
    chain<<"INFORMACJE O POCIAGU\n";
    chain<<"Masa Maksymalna Pociagu: "<<getMasaMaksymalna()<<endl;
    for(int i=0 ; i<wagony.size() ; i++)
        chain<<wagony[i]->toString();
    chain<<"Laczna masa wagonow: "<<pobierzLacznaMaseDopuszczalnaWagonow()<<endl;
    chain<<"Laczna Liczba wagonow: "<<pobierzLiczbeWagonow()<<endl;
    chain<<"Srednia masa wagonow: "<<pobierzSredniaMaseDopuszczalnaWagonow()<<endl;

    return chain.str();
}
