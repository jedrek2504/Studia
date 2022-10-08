//
// Created by student on 14.05.2022.
//

#ifndef KOLOKWIUM_RAKIETAKOSMICZNA_H
#define KOLOKWIUM_RAKIETAKOSMICZNA_H
#include <iostream>
#include <memory>
#include <vector>
#include "Element.h"

class RakietaKosmiczna
{
    int pojemnosc;
    std::vector<Element_ptr> elementy;

public:

    RakietaKosmiczna(int pojemnosc);

    virtual ~RakietaKosmiczna();

    int getPojemnosc() const;

    bool zaladuj(Element_ptr element);
    bool usun(Element_ptr element);

    int pobierzLiczbeElementow();
    int pobierzZajeteMiejsce();

    std::string toString();



};
typedef std::shared_ptr<RakietaKosmiczna> RakietaKosmiczna_ptr; //
#endif //KOLOKWIUM_RAKIETAKOSMICZNA_H
