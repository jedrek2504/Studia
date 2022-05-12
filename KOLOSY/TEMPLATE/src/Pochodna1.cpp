#include "Pochodna1.h"

#include <sstream>

using namespace std;

std::string Pochodna1::toString() {
    stringstream chain;
    chain<<" "<<"KOMENTARZ"<<getPochodna1Zmienna()<<endl; //
    return Abstrakcyjna::toString()+chain.str(); //
}
