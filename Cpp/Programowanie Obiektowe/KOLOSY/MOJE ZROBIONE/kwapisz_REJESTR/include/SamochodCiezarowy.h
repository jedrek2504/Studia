#ifndef KWAPISZ_REJESTR_SAMOCHODCIEZAROWY_H
#define KWAPISZ_REJESTR_SAMOCHODCIEZAROWY_H
#include <iostream>
#include <memory>
#include "Pojazd.h"

class SamochodCiezarowy :public Pojazd
{

    int ladownosc;
public:

    SamochodCiezarowy(const std::string &nrRejestracyjny, int ladownosc);

    virtual ~SamochodCiezarowy();

    int getLadownosc() const;

    void setLadownosc(int ladownosc);

    std::string toString() override;

    void dodajPrzejechaneKilometry(int liczbaKm) override;

};
typedef std::shared_ptr<SamochodCiezarowy> SamochodCiezarowy_ptr;
#endif //KWAPISZ_REJESTR_SAMOCHODCIEZAROWY_H
