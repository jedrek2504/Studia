//
// Created by student on 14.05.2022.
//

#include "Budynek.h"
#include <sstream>

using namespace std;

void Budynek::dodaj_lokal(Lokal_ptr lokal) {
    lokale.push_back(lokal);
}

double Budynek::czynsz_calkowity() {
    double suma=0;
    for(int i=0 ; i<lokale.size() ; i++)
        suma+=lokale[i]->czynsz();
    return suma;
}

double Budynek::zysk(double wydatki_za_metr) {
    double calkowita_powierzchnia=0;
    for(int i=0 ; i<lokale.size() ; i++)
        calkowita_powierzchnia+=lokale[i]->getPowierzchniaWMetrach();
    return czynsz_calkowity() - (calkowita_powierzchnia*wydatki_za_metr);
}

Budynek::Budynek() {}

Budynek::~Budynek() {

}

std::string Budynek::toString() {
    stringstream chain;
    chain<<"INFORMACJE O BUDYNKU\n";
    chain<<"\tLOKALE:\n";
    for(int i=0 ; i<lokale.size() ; i++)
        chain<<lokale[i]->toString();
    chain<<"Czynsz calkowity lokali: "<<czynsz_calkowity()<<endl;
    chain<<"Zysk za budynek(przy zalozeniu ze placimy 8ziko za metr): "<<zysk(8)<<endl;
    return chain.str();
}
