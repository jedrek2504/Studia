#ifndef TEMPLATE_POCHODNA2_H
#define TEMPLATE_POCHODNA2_H




#include <iostream>
#include <memory>
#include "Abstrakcyjna.h" //

class Pochodna2 :public Abstrakcyjna //
{
    //POLE:
    std::string pochodna2Zmienna;
    int pochodna2Zmienna2;

public:

    std::string toString() override;


    const std::string &getPochodna2Zmienna() const; //-
    int getPochodna2Zmienna2() const;

};
typedef std::shared_ptr<Pochodna2> Pochodna2_ptr; //2xNAZWA






#endif
