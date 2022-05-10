//
// Created by pobi on 13.12.18.
//

#include "Towarowy.h"
#include <sstream>
Towarowy::Towarowy(int masaDopuszczalna, int pojemnoscSkrzyni) : Wagon(masaDopuszczalna),
                                                                 pojemnoscSkrzyni(pojemnoscSkrzyni) {}

int Towarowy::getPojemnoscSkrzyni() const {
    return pojemnoscSkrzyni;
}

std::string Towarowy::toString() {
    std::stringstream fin;
    fin <<"Masa: "<<this->getMasaDopuszczalna()<<" Pojemnosc: "<< pojemnoscSkrzyni <<" typ: Towarowy ";
    return fin.str();

}
