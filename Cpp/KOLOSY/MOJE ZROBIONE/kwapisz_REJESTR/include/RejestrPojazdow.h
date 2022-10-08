#ifndef KWAPISZ_REJESTR_REJESTRPOJAZDOW_H
#define KWAPISZ_REJESTR_REJESTRPOJAZDOW_H
#include <iostream>
#include <memory>
#include <vector>
#include "Pojazd.h"

class RejestrPojazdow
{
    int maxLiczbaPozycji;
    std::vector<Pojazd_ptr> pojazdy;

public:
    RejestrPojazdow(int maxLiczbaPozycji);

    virtual ~RejestrPojazdow();

    int getMaxLiczbaPozycji() const;

    void setMaxLiczbaPozycji(int maxLiczbaPozycji);

    bool dodajPojazd(Pojazd_ptr pojazd);
    bool usunPojazd(Pojazd_ptr pojazd);


    int pobierzLiczbePojazdow();
    double pobierzSredniaLiczbePrzejechanychKilometrow();

    std::string toString();



};
typedef std::shared_ptr<RejestrPojazdow> RejestrPojazdow_ptr;
#endif //KWAPISZ_REJESTR_REJESTRPOJAZDOW_H
