#ifndef _LOKAL_H
#define _LOKAL_H

#include <string>
#include <memory>
class Lokal
{
protected:
    double powierzchnia_w_metrach;
    double stawka_za_metr;
public:
    Lokal(double powierzchnia,double stawka);
    double stawka();
    double powierzchnia();
    virtual double czynsz();
    virtual std::string toString();
};

typedef std::shared_ptr<Lokal> Lokal_ptr;

#endif //_LOKAL_H
