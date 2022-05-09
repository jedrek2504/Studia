#include "biuro.h"

using namespace std;

#include <string>
#include <sstream>

Biuro::Biuro(double powierzchnia, double stawka, double koszty):
Lokal(powierzchnia,stawka),
koszty_dodatkowe(koszty)
{}

double Biuro::koszty()
{
    return koszty_dodatkowe;
}

double Biuro::czynsz()
{
    return stawka()*powierzchnia() + koszty();
}

std::string Biuro::toString()
{
    stringstream tekst;
    tekst<<"Biuro: "<<Lokal::toString()<<" Koszty dodatkowe:"<<koszty();
    return tekst.str();
}

