#ifndef TEMPLATE_ABSTRAKCYJNA_H
#define TEMPLATE_ABSTRAKCYJNA_H




#include <iostream>
#include <memory>

class Abstrakcyjna //
{
protected:
    //POLA:
    int wirtualnaZmienna;
public:

    virtual std::string toString();


};
typedef std::shared_ptr<Abstrakcyjna> Abstrakcyjna_ptr; //





#endif
