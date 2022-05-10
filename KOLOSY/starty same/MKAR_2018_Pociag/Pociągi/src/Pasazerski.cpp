//
// Created by pobi on 13.12.18.
//

#include "Pasazerski.h"
#include <sstream>
Pasazerski::Pasazerski(int masaDopuszczalna, int liczbaPasazerow) : Wagon(masaDopuszczalna),
                                                                    liczbaPasazerow(liczbaPasazerow) {}

int Pasazerski::getLiczbaPasazerow() const {
    return liczbaPasazerow;
}

std::string Pasazerski::toString() {
    std::stringstream fin;
    fin <<"Masa: "<<this->getMasaDopuszczalna()<<" Liczba pasazerow: "<< liczbaPasazerow<<" typ: Pasazerski ";;
    return fin.str();

}
