//
// Created by student on 16.05.2022.
//

#include "Skrzynka.h"
#include <sstream>

using namespace std;

bool Skrzynka::wlozOwoc(Owoc_ptr owoc) {
    if(owoc->getWaga()+pobierzMasaCalkowita() <= getMaxLadownosc())
    {
        owoce.push_back(owoc);
        return true;
    }
    else return false;
}

bool Skrzynka::usunOwoc(Owoc_ptr owoc) {
    for(int i=0 ; i<owoce.size() ; i++)
    {
        if(owoce[i] == owoc)
        {
            owoce[i] = nullptr;
            owoce.erase(owoce.begin()+i); //
            return true;
        }
    }
    return false;
}

float Skrzynka::pobierzCenaCalkowita() {
    float suma=0;
    for(auto & i : owoce)
        suma+=i->getCena();
    return suma;
}

float Skrzynka::pobierzMasaCalkowita() {
    float suma=0;
    for(auto & i : owoce)
        suma+=i->getWaga();
    return suma;
}

std::string Skrzynka::toString() {
    stringstream chain;
    chain<<"INFORMACJE O Skrzynce\n"; //
    chain<<"Maksymalna ladownosc Skrzynki: "<<getMaxLadownosc()<<endl; //
    chain<<"\tOwoce:\n"; //
    for(auto & i : owoce)
        chain<<i->toString();
    chain<<"Cena calkowita: "<<pobierzCenaCalkowita()<<endl;
    chain<<"Waga calkowita"<<pobierzMasaCalkowita()<<endl;
    return chain.str();
}

Skrzynka::Skrzynka(int maxLadownosc) : maxLadownosc(maxLadownosc) {}

int Skrzynka::getMaxLadownosc() const {
    return maxLadownosc;
}
