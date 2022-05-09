#ifndef _BUDYNEK_H
#define _BUDYNEK_H

#include "lokal.h"
#include <vector>

class Budynek
{
private:
    std::vector<Lokal_ptr> lokale;
public:
    Budynek();
    ~Budynek();
    void dodaj_lokal(Lokal_ptr lokal);
    double czynsz_calkowity();
    double zysk(double wydatki_za_metr);
};

typedef std::shared_ptr<Budynek> Budynek_ptr;

#endif //_BUDYNEK_H
