#ifndef KWAPISZ_REJESTR_SAMOCHODOSOBOWY_H
#define KWAPISZ_REJESTR_SAMOCHODOSOBOWY_H
#include <iostream>
#include <memory>
#include "Pojazd.h"

class SamochodOsobowy :public Pojazd
{

    int liczbaMiejsc;
public:
    SamochodOsobowy(const std::string &nrRejestracyjny, int liczbaMiejsc);

    virtual ~SamochodOsobowy();

    int getLiczbaMiejsc() const;

    void setLiczbaMiejsc(int liczbaMiejsc);

    std::string toString() override;
    void dodajPrzejechaneKilometry(int liczbaKm) override;


};
typedef std::shared_ptr<SamochodOsobowy> SamochodOsobowy_ptr;
#endif //KWAPISZ_REJESTR_SAMOCHODOSOBOWY_H
