#include "../include/SamochodOsobowy.h"
#include <sstream>

using namespace std;

std::string SamochodOsobowy::toString() {
    stringstream chain;
    chain<<" "<<"Typ pojazdu: Osobowy"<<" Liczba Miejsc: "<<getLiczbaMiejsc()<<endl;
    return Pojazd::toString()+chain.str();
}

SamochodOsobowy::~SamochodOsobowy() {

}

int SamochodOsobowy::getLiczbaMiejsc() const {
    return liczbaMiejsc;
}

void SamochodOsobowy::setLiczbaMiejsc(int liczbaMiejsc) {
    SamochodOsobowy::liczbaMiejsc = liczbaMiejsc;
}

void SamochodOsobowy::dodajPrzejechaneKilometry(int liczbaKm) {

    setLiczbaPrzejechanychKilometrow(getLiczbaPrzejechanychKilometrow()+liczbaKm);
}

SamochodOsobowy::SamochodOsobowy(const string &nrRejestracyjny, int liczbaMiejsc) : Pojazd(nrRejestracyjny),
                                                                                    liczbaMiejsc(liczbaMiejsc) {}




