#include "Glowna.h"

#include <sstream>

using namespace std;

int Glowna::pobierzLiczbe() { //

    return elementy.size(); //

}

int Glowna::pobierzLaczna() {

    int suma=0;
    for(int i=0 ; i<elementy.size() ; i++) //
        suma+=elementy[i]->getWirtualnaZmienna(); //
    return suma;

}

float Glowna::pobierzSrednia() {

    if(pobierzLiczbe()!=0) return (float)pobierzLaczna()/(float)pobierzLiczbe(); //
    else return 0;

}

bool Glowna::dodaj(Abstrakcyjna_ptr element) {

    if(element->getWirtualnaZmienna()+pobierzLaczna() <= getPojemnosc()) //
    {
        elementy.push_back(element);
        return true;
    }
    else return false;

}

bool Glowna::usun(Abstrakcyjna_ptr element) {

    for(int i=0 ; i<elementy.size() ; i++) //
    {
        if(elementy[i] == element) //
        {
            elementy[i] = nullptr; //
            elementy.erase(elementy.begin()+i); //
            return true;
        }
    }
    return false;

}

std::string Glowna::toString() {

    stringstream chain;
    chain<<"INFORMACJE O GLOWNA\n"; //
    chain<<"Pojemnosc GLOWNEJ: "<<getPojemnosc()<<endl; //
    chain<<"\tElementy:\n"; //
    for(int i=0 ; i<elementy.size() ; i++)
        chain<<elementy[i]->toString();
    chain<<"KOMENTARZ"<<pobierzLiczbe()<<endl;
    chain<<"KOMENTARZ"<<pobierzLaczna()<<endl;
    return chain.str();

}



