//
// Created by student on 14.05.2022.
//

#ifndef KOLOKWIUM_ELEMENT_H
#define KOLOKWIUM_ELEMENT_H
#include <iostream>
#include <memory>

class Element
{
protected:
    int rozmiar;
public:
    Element(int rozmiar);

    virtual ~Element();

    int getRozmiar() const;

    virtual std::string toString();
};
typedef std::shared_ptr<Element> Element_ptr;

#endif //KOLOKWIUM_ELEMENT_H
