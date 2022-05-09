#ifndef RACKMKAR2019_SERWER_H
#define RACKMKAR2019_SERWER_H
#include <iostream>
#include <memory>
#include "Polka.h"

class Serwer :public Polka
{
    int mocCalkowita;
public:
    Serwer(const std::string &nazwa, int mocCalkowita);
    virtual ~Serwer();

    int getMocCalkowita();
    void setMocCalkowita(int mocCalkowita);

    std::string toString() override;
    int obliczWydzielanaMoc() override;
};
typedef std::shared_ptr<Serwer> SerwerPtr; //smartpointer serwer


#endif //RACKMKAR2019_SERWER_H
