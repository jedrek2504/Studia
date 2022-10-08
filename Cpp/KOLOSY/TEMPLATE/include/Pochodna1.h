#ifndef TEMPLATE_POCHODNA1_H
#define TEMPLATE_POCHODNA1_H




#include <iostream>
#include <memory>
#include "Abstrakcyjna.h" //

class Pochodna1 :public Abstrakcyjna  //
{
    //POLE:
    std::string pochodna1Zmienna;
public:

    std::string toString() override;



};
typedef std::shared_ptr<Pochodna1> Pochodna1_ptr; //




#endif
