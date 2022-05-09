#ifndef _MIESZKANIE_H
#define _MIESZKANIE_H

#include "lokal.h"

class Mieszkanie:public Lokal
{
public:
    Mieszkanie(double powierzchnia,double stawka);
    double czynsz();
    std::string toString();
};

typedef std::shared_ptr<Mieszkanie> Mieszkanie_ptr;

#endif //_MIESZKANIE_H
