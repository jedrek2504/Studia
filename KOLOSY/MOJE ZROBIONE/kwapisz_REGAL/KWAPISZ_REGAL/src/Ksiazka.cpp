#include "Ksiazka.h"
#include <sstream>

using namespace std;

Ksiazka::Ksiazka(const std::string &tytul, const std::string &autor, int rozmiar) : Element(rozmiar), tytul(tytul),
                                                                                    autor(autor) {}

Ksiazka::~Ksiazka() {

}

const std::string &Ksiazka::getTytul() const {
    return tytul;
}

void Ksiazka::setTytul(const std::string &tytul) {
    Ksiazka::tytul = tytul;
}

const std::string &Ksiazka::getAutor() const {
    return autor;
}

void Ksiazka::setAutor(const std::string &autor) {
    Ksiazka::autor = autor;
}

std::string Ksiazka::toString() {
    stringstream chain;
    chain<<" "<<"Typ elementu: Ksiazka Autor: "<<getAutor()<<" Tytul: "<<getTytul()<<endl;
    return Element::toString()+chain.str();
}


