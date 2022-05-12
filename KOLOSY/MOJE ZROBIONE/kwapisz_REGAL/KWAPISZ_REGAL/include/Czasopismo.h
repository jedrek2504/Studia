#ifndef KWAPISZ_REGAL_CZASOPISMO_H
#define KWAPISZ_REGAL_CZASOPISMO_H
#include <iostream>
#include <memory>
#include "Element.h"

class Czasopismo :public Element
{
    std::string nazwa;

public:
    Czasopismo(const std::string &nazwa, int rozmiar);

    virtual ~Czasopismo();

    const std::string &getNazwa() const;

    void setNazwa(const std::string &nazwa);

    std::string toString() override;
};
typedef std::shared_ptr<Czasopismo> Czasopismo_ptr;

#endif //KWAPISZ_REGAL_CZASOPISMO_H
