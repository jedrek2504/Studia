#ifndef KWAPISZ_REGAL_REGAL_H
#define KWAPISZ_REGAL_REGAL_H
#include <iostream>
#include <memory>
#include <vector>
#include "Element.h"

class Regal
{
    int pojemnosc;
    std::vector<Element_ptr> elementy;

public:
    explicit Regal(int pojemnosc);

    virtual ~Regal();

    int getPojemnosc() const;

    void setPojemnosc(int pojemnosc);

    bool odloz(Element_ptr element);
    bool usun(Element_ptr element);
    int pobierzLiczbeElementow();
    int pobierzZajeteMiejsce();





    std::string toString();
};
typedef std::shared_ptr<Regal> Regal_ptr;


#endif //KWAPISZ_REGAL_REGAL_H
