//
// Created by student on 14.05.2022.
//

#include "RakietaKosmiczna.h"
#include <sstream>

using namespace std;

std::string RakietaKosmiczna::toString() {
    stringstream chain;
    chain<<"INFORMACJE O Rakiecie\n";
    chain<<"Pojemnosc rakiety: "<<getPojemnosc()<<endl;
    chain<<"\tElementy:\n";
    for(int i=0 ; i<RakietaKosmiczna::elementy.size() ; i++)
        chain<<RakietaKosmiczna::elementy[i]->toString();
    chain<<"Liczba elementow: "<<pobierzLiczbeElementow()<<endl;
    chain<<"Zajete miejsce: "<<pobierzZajeteMiejsce()<<endl;
    return chain.str();
}

RakietaKosmiczna::RakietaKosmiczna(int pojemnosc) : pojemnosc(pojemnosc) {}

RakietaKosmiczna::~RakietaKosmiczna() = default;

bool RakietaKosmiczna::zaladuj(Element_ptr element) {
    if(element->getRozmiar()+pobierzZajeteMiejsce() <= getPojemnosc())
    {
        RakietaKosmiczna::elementy.push_back(element);
        return true;
    }
    else return false;
}

bool RakietaKosmiczna::usun(Element_ptr element) {
    for(int i=0 ; i<RakietaKosmiczna::elementy.size() ; i++)
    {
        if(RakietaKosmiczna::elementy[i] == element)
        {
            RakietaKosmiczna::elementy[i] = nullptr;
            RakietaKosmiczna::elementy.erase(elementy.begin()+i);
            return true;
        }
    }
    return false;
}

int RakietaKosmiczna::pobierzLiczbeElementow() {
    return RakietaKosmiczna::elementy.size();
}

int RakietaKosmiczna::pobierzZajeteMiejsce() {
    int suma=0;
    for(int i=0 ; i<elementy.size() ; i++)
        suma+=RakietaKosmiczna::elementy[i]->getRozmiar();
    return suma;
}

int RakietaKosmiczna::getPojemnosc() const {
    return pojemnosc;
}

