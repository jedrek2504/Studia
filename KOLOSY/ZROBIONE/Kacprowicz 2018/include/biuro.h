#ifndef _BIURO_H
#define _BIURO_H

#include "lokal.h"

class Biuro:public Lokal
{
protected:
    double koszty_dodatkowe;
public:
    Biuro(double powierzchnia,double stawka,double koszty);
    double czynsz();
    double koszty();
    std::string toString();
};

typedef std::shared_ptr<Biuro> Biuro_ptr;

#endif //_BIURO_H