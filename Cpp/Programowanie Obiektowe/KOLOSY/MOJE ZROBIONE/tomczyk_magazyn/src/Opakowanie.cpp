#include "../include/Opakowanie.h"
#include <sstream>

using namespace std;

Opakowanie::Opakowanie(int id) : id(id) {}

Opakowanie::~Opakowanie() = default;

int Opakowanie::getId() const {
    return id;
}

void Opakowanie::setId(int id) {
    Opakowanie::id = id;
}

std::string Opakowanie::opis() {
    stringstream chain;
    chain<<"Id opakowania: "<<getId();
    return chain.str();
}
