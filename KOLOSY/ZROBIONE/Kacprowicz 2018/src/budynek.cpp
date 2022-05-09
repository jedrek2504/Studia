#include "budynek.h"


using namespace std;

#include <string>
#include <sstream>

Budynek::Budynek() {}
Budynek::~Budynek() {}

void Budynek::dodaj_lokal(Lokal_ptr lokal)
{
    lokale.push_back(lokal);
}

double Budynek::czynsz_calkowity()
{
    double suma;
    for(auto i:lokale)
    {
        suma=suma + i->czynsz();
    }
    return suma;
}

double Budynek::zysk(double wydatki_za_metr)
{
    double wynik,powierzchnia_cal;
    for(auto i:lokale)
    {
        powierzchnia_cal = powierzchnia_cal + i->powierzchnia();
    }
    wynik = czynsz_calkowity() - (powierzchnia_cal*wydatki_za_metr);
    return wynik;
}