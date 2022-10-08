#include "Mieszkanie.h"
#include <sstream>

using namespace std;
std::string Mieszkanie::toString() {
    stringstream chain;
    chain<<" "<<"Typ Lokalu: Mieskzanie"<<" Czynsz: "<<czynsz()<<endl;
    return Lokal::toString()+chain.str();
}

double Mieszkanie::czynsz() {
    return (getStawkaZaMetr()*getPowierzchniaWMetrach());
}

Mieszkanie::Mieszkanie(double powierzchnia, double stawka) : Lokal(powierzchnia, stawka) {}

Mieszkanie::~Mieszkanie() {

}
