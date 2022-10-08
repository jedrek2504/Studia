#include "../include/RejestrPojazdow.h"
#include <sstream>

using namespace std;

RejestrPojazdow::RejestrPojazdow(int maxLiczbaPozycji) : maxLiczbaPozycji(maxLiczbaPozycji) {}

RejestrPojazdow::~RejestrPojazdow() {

}

int RejestrPojazdow::getMaxLiczbaPozycji() const {
    return maxLiczbaPozycji;
}

void RejestrPojazdow::setMaxLiczbaPozycji(int maxLiczbaPozycji) {
    RejestrPojazdow::maxLiczbaPozycji = maxLiczbaPozycji;
}

bool RejestrPojazdow::dodajPojazd(Pojazd_ptr pojazd) {
    if(pojazdy.size() < getMaxLiczbaPozycji())
    {
        pojazdy.push_back(pojazd);
        return true;
    }
    else return false;
}

bool RejestrPojazdow::usunPojazd(Pojazd_ptr pojazd) {
    for(int i=0 ; i<pojazdy.size() ; i++)
    {
        if(pojazdy[i] == pojazd)
        {
            pojazdy[i] = nullptr;
            pojazdy.erase(pojazdy.begin()+i);
            return true;
        }
    }
    return false;
}

int RejestrPojazdow::pobierzLiczbePojazdow() {
    return pojazdy.size();
}

double RejestrPojazdow::pobierzSredniaLiczbePrzejechanychKilometrow() {
    double suma=0;
    for(int i=0 ; i<pojazdy.size() ; i++)
        suma+=pojazdy[i]->getLiczbaPrzejechanychKilometrow();

    if(pobierzLiczbePojazdow()!=0) return suma/(double)pobierzLiczbePojazdow();
    else return 0;
}

std::string RejestrPojazdow::toString() {
    stringstream chain;
    chain<<"INFORMACJE O REJESTRZE POJAZDOW\n"; //
    chain<<"Maksymalna liczba pozycji REJESTRU: "<<getMaxLiczbaPozycji()<<endl; //
    chain<<"\tElementy:\n"; //
    for(int i=0 ; i<pojazdy.size() ; i++)
        chain<<pojazdy[i]->toString();
    chain<<"Liczba pojazdow: "<<pobierzLiczbePojazdow()<<endl;
    chain<<"Srednia liczba przejechanych kilometrow: "<<pobierzSredniaLiczbePrzejechanychKilometrow()<<endl;
    return chain.str();
}
