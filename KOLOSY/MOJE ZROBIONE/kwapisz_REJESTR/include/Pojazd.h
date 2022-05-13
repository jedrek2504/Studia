#ifndef KWAPISZ_REJESTR_POJAZD_H
#define KWAPISZ_REJESTR_POJAZD_H
#include <iostream>
#include <memory>

class Pojazd //
{
protected:

    std::string nrRejestracyjny;
    int liczbaPrzejechanychKilometrow;

public:
    explicit Pojazd(const std::string &nrRejestracyjny);

    Pojazd();

    virtual ~Pojazd();

    const std::string &getNrRejestracyjny() const;

    void setNrRejestracyjny(const std::string &nrRejestracyjny);

    int getLiczbaPrzejechanychKilometrow() const;

    void setLiczbaPrzejechanychKilometrow(int liczbaPrzejechanychKilometrow);

    virtual std::string toString();

    virtual void dodajPrzejechaneKilometry(int liczbaKm)=0; //PAMIETAC ZE DODAWANIE MUSI BYC VOIDEM CZY COS

};
typedef std::shared_ptr<Pojazd> Pojazd_ptr;

#endif //KWAPISZ_REJESTR_POJAZD_H
