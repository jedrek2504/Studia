#include "Abstrakcyjna.h"

#include <sstream>

using namespace std;

std::string Abstrakcyjna::toString() {
    stringstream chain;
    chain<<"KOMENTARZ"<<getWirtualnaZmienna(); //KOMENTARZ + METODA
    return chain.str();
}
