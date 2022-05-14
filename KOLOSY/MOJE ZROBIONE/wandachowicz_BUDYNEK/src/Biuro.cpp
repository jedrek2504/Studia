//
// Created by student on 14.05.2022.
//

#include "Biuro.h"
#include <sstream>

using namespace std;
std::string Biuro::toString() {
    stringstream chain;
    chain<<" "<<"Typ Lokalu: Biuro"<<" Koszty dodatkowe: "<<getKosztyDodatkowe()<<" Czynsz: "<<czynsz()<<endl;
    return Lokal::toString()+chain.str();
}

double Biuro::czynsz() {
    return (getStawkaZaMetr()*getPowierzchniaWMetrach())+getKosztyDodatkowe();
}

Biuro::Biuro(double powierzchnia, double stawka, double koszty) : Lokal(powierzchnia,
                                                                        stawka),
                                                                                         koszty_dodatkowe(
                                                                                                 koszty) {}

double Biuro::getKosztyDodatkowe() const {
    return koszty_dodatkowe;
}

void Biuro::setKosztyDodatkowe(double kosztyDodatkowe) {
    koszty_dodatkowe = kosztyDodatkowe;
}
