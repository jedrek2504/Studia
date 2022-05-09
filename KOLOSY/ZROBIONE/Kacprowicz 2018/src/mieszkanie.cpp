#include "mieszkanie.h"

using namespace std;

#include <string>
#include <sstream>

Mieszkanie::Mieszkanie(double powierzchnia, double stawka):
Lokal(powierzchnia,stawka)
{}

double Mieszkanie::czynsz()
{
    return stawka()*powierzchnia();
}

std::string Mieszkanie::toString()
{
    stringstream tekst;
    tekst<<"Mieszkanie: "<<Lokal::toString();
    return tekst.str();
}