//
// Created by student on 14.05.2022.
//

#include "LazikMarsjanski.h"
#include <sstream>

using namespace std;

std::string LazikMarsjanski::toString() {
    stringstream chain;
    chain<<" "<<"Typ elementu: Lazik Marsjanski"<<" Nazwa: "<<getNazwa()<<" Tworca: "<<getTworca()<<endl;
    return Element::toString()+chain.str();
}

LazikMarsjanski::LazikMarsjanski(int rozmiar, const std::string &nazwa, const std::string &tworca) : Element(rozmiar),
                                                                                                     nazwa(nazwa),
                                                                                                     tworca(tworca) {}

LazikMarsjanski::~LazikMarsjanski() {

}

const std::string &LazikMarsjanski::getNazwa() const {
    return nazwa;
}

const std::string &LazikMarsjanski::getTworca() const {
    return tworca;
}
