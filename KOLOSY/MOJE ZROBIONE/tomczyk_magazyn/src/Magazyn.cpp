#include "../include/Magazyn.h"
#include <sstream>

using namespace std;

int Magazyn::liczbaOpakowan() {
    return opakowania.size();
}

bool Magazyn::wstaw(OpakowaniePtr opakowanie) {
    if(opakowanie->objetosc() <= dostepnaPojemnosc())
    {
        opakowania.push_back(opakowanie);
        return true;
    }
    else return false;
}

bool Magazyn::wyjmij(OpakowaniePtr opakowanie) {
    for(int i=0 ; i<opakowania.size() ; i++)
    {
        if(opakowania[i] == opakowanie)
        {
            opakowania[i] = nullptr;
            opakowania.erase(opakowania.begin()+i);
            return true;
        }
    }
    return false;
}

std::string Magazyn::opis() {
    stringstream chain;
    chain<<"INFORMACJE O MAGAZYNIE\n"; //
    chain<<"Pojemnosc magazynu: "<<getPojemnosc()<<endl;
    chain<<"\tElementy:\n"; //
    for(int i=0 ; i<opakowania.size() ; i++)
        chain<<opakowania[i]->opis();
    chain<<"Dostepne miejsce: "<<dostepnaPojemnosc()<<endl;
    chain<<"Liczba opakowan: "<<liczbaOpakowan()<<endl;
    return chain.str();
}

Magazyn::Magazyn(double pojemnosc) : pojemnosc(pojemnosc) {}

Magazyn::~Magazyn() {

}

double Magazyn::getPojemnosc() const {
    return pojemnosc;
}

void Magazyn::setPojemnosc(double pojemnosc) {
    Magazyn::pojemnosc = pojemnosc;
}

double Magazyn::dostepnaPojemnosc() {
    double suma=0;
    for(int i=0 ; i<opakowania.size() ; i++)
        suma+=opakowania[i]->objetosc();
    return getPojemnosc() - suma;
}
