#ifndef WANDACHOWICZ_BUDYNEK_LOKAL_H
#define WANDACHOWICZ_BUDYNEK_LOKAL_H
#include <iostream>
#include <memory>

class Lokal //
{
protected:
    //POLA:
    double powierzchnia_w_metrach;
    double stawka_za_metr;

public:
    Lokal(double powierzchniaWMetrach, double stawkaZaMetr);

    virtual ~Lokal();

    double getPowierzchniaWMetrach() const;

    void setPowierzchniaWMetrach(double powierzchniaWMetrach);

    double getStawkaZaMetr() const;

    void setStawkaZaMetr(double stawkaZaMetr);

    virtual double czynsz()=0;

    virtual std::string toString();
};
typedef std::shared_ptr<Lokal> Lokal_ptr;
#endif //WANDACHOWICZ_BUDYNEK_LOKAL_H
