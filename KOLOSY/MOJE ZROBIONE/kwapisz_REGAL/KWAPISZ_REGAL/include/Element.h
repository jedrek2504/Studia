#ifndef KWAPISZ_REGAL_ELEMENT_H
#define KWAPISZ_REGAL_ELEMENT_H
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

    void setRozmiar(int rozmiar);

    virtual std::string toString();
};
typedef std::shared_ptr<Element> Element_ptr;

#endif //KWAPISZ_REGAL_ELEMENT_H
