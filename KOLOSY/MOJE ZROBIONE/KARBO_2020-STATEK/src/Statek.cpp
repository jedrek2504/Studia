#include <iostream>
#include <sstream>
#include "Statek.h"
#include "Ladunek.h"

using namespace std;

bool Statek::dodajLadunek(Ladunek_ptr ladunek) {
    if(ladunek->obliczMase()+this->pobierzLacznaMaseLadunkow()<=ladownosc)
    {
        ladunki.push_back(ladunek);
        return true;
    }
    else return false;
}

bool Statek::usunLadunek(Ladunek_ptr ladunek) {
    for(int i=0 ; i<ladunki.size() ; i++)
    {
        if(ladunki[i] == ladunek)
        {
            ladunki.erase(ladunki.begin() + i);
            return true;
        }
    }
    return false;
}

int Statek::pobierzLiczbeLadunkow() {
    return ladunki.size();
}

int Statek::pobierzLacznaMaseLadunkow() {
    int lacznaMasa=0;
    for(int i=0 ; i<ladunki.size() ; i++)
        lacznaMasa+=ladunki[i]->obliczMase();
    return lacznaMasa;
}

double Statek::pobierzSredniaMaseLadunkow() {
    if(pobierzLiczbeLadunkow()!=0) return (double)pobierzLacznaMaseLadunkow()/(double)pobierzLiczbeLadunkow();
    else return 0;
}

string Statek::toString()
{
    stringstream chain;
    chain << "INFORMACJE O STATKU:\n";
    chain << "Pozostala ladownosc: "<<getLadownosc()<<'\n';
    chain << "\tInformacje o ladunkach:\n"<<this->getLadunkiInfo()<<endl;
    return chain.str();
}

Statek::Statek(int ladownosc) : ladownosc(ladownosc) {}

int Statek::getLadownosc() const {
    return ladownosc;
}

void Statek::setLadownosc(int ladownosc) {
    Statek::ladownosc = ladownosc;
}

std::string Statek::getLadunkiInfo() {
    stringstream chain;
    for (auto & i : ladunki) {
        chain << "Nazwa ladunku: "<<i->getNazwa() << " Laczna masa ladunku: " << i->obliczMase()<< endl;
    }
    return chain.str();
}



