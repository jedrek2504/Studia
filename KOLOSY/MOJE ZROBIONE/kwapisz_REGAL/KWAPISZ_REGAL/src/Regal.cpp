#include "Regal.h"
#include <sstream>

using namespace std;

std::string Regal::toString() {
    stringstream chain;
    chain<<"INFORMACJE O REGALE\n";
    chain<<"Pojemnosc regalu: "<<getPojemnosc()<<endl;
    chain<<"\tElementy:\n";
    for(int i=0 ; i<elementy.size() ; i++)
        chain<<elementy[i]->toString();
    chain<<"Liczba elementow na regale: "<<pobierzLiczbeElementow()<<endl;
    chain<<"Zajete miejsce na regale: "<<pobierzZajeteMiejsce()<<endl;
    return chain.str();
}

Regal::Regal(int pojemnosc) : pojemnosc(pojemnosc) {}

Regal::~Regal() {

}

int Regal::getPojemnosc() const {
    return pojemnosc;
}

void Regal::setPojemnosc(int pojemnosc) {
    Regal::pojemnosc = pojemnosc;
}

bool Regal::odloz(Element_ptr element) {
    if(element->getRozmiar()+pobierzZajeteMiejsce() <= getPojemnosc())
    {
        elementy.push_back(element);
        return true;
    }
    else return false;
}

bool Regal::usun(Element_ptr element) {
    for(int i=0 ; i<elementy.size() ; i++)
    {
        if(elementy[i] == element)
        {
            elementy[i] = nullptr;
            elementy.erase(elementy.begin()+i);
            return true;
        }
    }
    return false;
}

int Regal::pobierzLiczbeElementow() {
    return elementy.size();
}

int Regal::pobierzZajeteMiejsce() {
    int suma=0;
    for(int i=0 ; i<elementy.size() ; i++)
        suma+=elementy[i]->getRozmiar();
    return suma;

}
