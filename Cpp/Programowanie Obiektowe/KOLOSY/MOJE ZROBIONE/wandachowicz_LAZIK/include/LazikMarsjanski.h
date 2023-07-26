//
// Created by student on 14.05.2022.
//

#ifndef KOLOKWIUM_LAZIKMARSJANSKI_H
#define KOLOKWIUM_LAZIKMARSJANSKI_H
#include <iostream>
#include <memory>
#include "Element.h"

class LazikMarsjanski :public Element
{
    std::string nazwa;
    std::string tworca;

public:
    LazikMarsjanski(int rozmiar, const std::string &nazwa, const std::string &tworca);

    virtual ~LazikMarsjanski();

    const std::string &getNazwa() const;

    const std::string &getTworca() const;

    std::string toString() override;
};
typedef std::shared_ptr<LazikMarsjanski> LazikMarsjanski_ptr;
#endif //KOLOKWIUM_LAZIKMARSJANSKI_H
