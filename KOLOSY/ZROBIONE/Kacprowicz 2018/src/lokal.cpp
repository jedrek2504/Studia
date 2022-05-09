#include "lokal.h"

using namespace std;

#include <string>
#include <sstream>

double Lokal::powierzchnia()
{
    return powierzchnia_w_metrach;
}
double Lokal::stawka()
{
    return stawka_za_metr;
};
double Lokal::czynsz()
{
    return 0;
};

Lokal::Lokal(double powierzchnia, double stawka):
powierzchnia_w_metrach(powierzchnia),
stawka_za_metr(stawka)
{}

std::string Lokal::toString()
{
    stringstream tekst;
    tekst<<"Powierzchnia: "<<powierzchnia()<<" Stawka za metr: "<<stawka();
    return tekst.str();
}
