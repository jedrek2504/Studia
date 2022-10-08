//
// Created by student on 14.05.2022.
//

#include "Lokal.h"
#include <sstream>

using namespace std;

std::string Lokal::toString() {
    stringstream chain;
    chain<<"Powierzchnia[m^2]: "<<getPowierzchniaWMetrach()<<" Stawka za metr: "<<getStawkaZaMetr();
    return chain.str();
}

Lokal::Lokal(double powierzchniaWMetrach, double stawkaZaMetr) : powierzchnia_w_metrach(powierzchniaWMetrach),
                                                                 stawka_za_metr(stawkaZaMetr) {}

Lokal::~Lokal() {

}

double Lokal::getPowierzchniaWMetrach() const {
    return powierzchnia_w_metrach;
}

void Lokal::setPowierzchniaWMetrach(double powierzchniaWMetrach) {
    powierzchnia_w_metrach = powierzchniaWMetrach;
}

double Lokal::getStawkaZaMetr() const {
    return stawka_za_metr;
}

void Lokal::setStawkaZaMetr(double stawkaZaMetr) {
    stawka_za_metr = stawkaZaMetr;
}

double Lokal::czynsz() {
    return 0;
}
