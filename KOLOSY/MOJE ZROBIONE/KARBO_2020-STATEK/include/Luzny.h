#ifndef START_STATEK_LUZNY_H
#define START_STATEK_LUZNY_H
#include <iostream>
#include "Ladunek.h"
#include <memory>

class Luzny :public Ladunek
{
    int masaLadunku;
public:
    Luzny(std::string nazwa, int masaLadunku);

    int obliczMase();
    std::string toString();

    int getMasaLadunku() const;
    void setMasaLadunku(int masaLadunku);

    virtual ~Luzny();
};
typedef std::shared_ptr<Luzny> Luzny_ptr;

#endif //START_STATEK_LUZNY_H
