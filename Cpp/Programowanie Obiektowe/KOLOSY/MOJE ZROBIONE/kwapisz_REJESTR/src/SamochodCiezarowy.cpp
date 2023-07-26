#include "../include/SamochodCiezarowy.h"
#include <sstream>

using namespace std;

std::string SamochodCiezarowy::toString() {
    stringstream chain;
    chain<<" "<<"Typ pojazdu: Ciezarowy"<<" Ladownosc: "<<getLadownosc()<<endl;
    return Pojazd::toString()+chain.str();
}



SamochodCiezarowy::~SamochodCiezarowy() {

}

int SamochodCiezarowy::getLadownosc() const {
    return ladownosc;
}

void SamochodCiezarowy::setLadownosc(int ladownosc) {
    SamochodCiezarowy::ladownosc = ladownosc;
}

void SamochodCiezarowy::dodajPrzejechaneKilometry(int liczbaKm) {
    setLiczbaPrzejechanychKilometrow(getLiczbaPrzejechanychKilometrow()+liczbaKm);
}

SamochodCiezarowy::SamochodCiezarowy(const string &nrRejestracyjny, int ladownosc) : Pojazd(nrRejestracyjny),
                                                                                     ladownosc(ladownosc) {}
