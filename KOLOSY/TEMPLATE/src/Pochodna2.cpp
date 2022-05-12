#include "Pochodna2.h"

#include <sstream>

using namespace std;

std::string Pochodna2::toString() {
    stringstream chain;
    chain<<" "<<"KOMENTARZ"<<getPochodna2Zmienna()<<" "<<"KOMENTARZ"<<getPochodna2Zmienna2()<<endl; //
    return Abstrakcyjna::toString()+chain.str(); //
}

