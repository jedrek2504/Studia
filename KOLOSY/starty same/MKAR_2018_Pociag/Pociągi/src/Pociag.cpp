//
// Created by pobi on 13.12.18.
//

#include "Pociag.h"
#include "Wagon.h"
#include <sstream>
Pociag::Pociag(int masaMaksymalna) : masaMaksymalna(masaMaksymalna) {}

Pociag::~Pociag() {}

int Pociag::pobierzLiczbeWagonow() {
    return wagony.size();
}

bool Pociag::dodajWagon(Wagon_ptr wagon) {
    int limit;
    limit = pobierzLacznaMaseDopuszczalnaWagonow()+wagon->getMasaDopuszczalna();
    if(limit>masaMaksymalna)
        return false;
    else
    {wagony.push_back(wagon);
        return true;}


}

void Pociag::usunWagon(Wagon_ptr wagon) {
    for(int i=0;i<wagony.size();i++)
    {
        if(wagony[i] == wagon)
        {
            wagony.erase(wagony.begin()+i);
        }
    }
}

int Pociag::pobierzLacznaMaseDopuszczalnaWagonow() {
    int masa = 0;
    for(auto it:wagony)
    {masa+=it->getMasaDopuszczalna();}

    return masa;
}

int Pociag::getMasaMaksymalna() const {
    return masaMaksymalna;
}

float Pociag::pobierzSredniaMaseDopuszczalnaWagonow() {
    float srednia = 0.0;
    if(wagony.size()==0)
        return 0.0;
    else{
        srednia = (pobierzLacznaMaseDopuszczalnaWagonow() / wagony.size());
        return srednia;
    }

}

std::string Pociag::toString() {
    std::string temp;
    for(auto it:wagony)
    {
        temp += it->toString() + "\n";
    }
    return temp;

}
