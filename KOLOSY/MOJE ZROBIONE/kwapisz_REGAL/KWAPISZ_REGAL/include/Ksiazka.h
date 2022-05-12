#ifndef KWAPISZ_REGAL_KSIAZKA_H
#define KWAPISZ_REGAL_KSIAZKA_H
#include <iostream>
#include <memory>
#include "Element.h"

class Ksiazka :public Element
{
    std::string tytul;
    std::string autor;

public:

    Ksiazka(const std::string &tytul, const std::string &autor, int rozmiar);

    virtual ~Ksiazka();

    const std::string &getTytul() const;

    void setTytul(const std::string &tytul);

    const std::string &getAutor() const;

    void setAutor(const std::string &autor);

    std::string toString() override;
};
typedef std::shared_ptr<Ksiazka> Ksiazka_ptr;

#endif //KWAPISZ_REGAL_KSIAZKA_H
