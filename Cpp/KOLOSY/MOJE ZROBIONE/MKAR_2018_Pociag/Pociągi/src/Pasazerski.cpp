#include "Pasazerski.h"
#include <sstream>

using namespace std;

std::string Pasazerski::toString() {
    stringstream chain;
    chain<<Wagon::toString()<<" liczba Pasazerow: "<<getLiczbaPasazerow()<<'\n';
    return chain.str();
}

Pasazerski::Pasazerski(int masaDopuszczalna, int liczbaPasazerow) : Wagon(masaDopuszczalna),
                                                                    liczbaPasazerow(liczbaPasazerow) {}

Pasazerski::~Pasazerski() {

}

int Pasazerski::getLiczbaPasazerow() const {
    return liczbaPasazerow;
}

void Pasazerski::setLiczbaPasazerow(int liczbaPasazerow) {
    Pasazerski::liczbaPasazerow = liczbaPasazerow;
}
