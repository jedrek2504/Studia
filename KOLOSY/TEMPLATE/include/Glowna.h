#ifndef TEMPLATE_GLOWNA_H
#define TEMPLATE_GLOWNA_H




#include <iostream>
#include <memory>
#include <vector>
#include "Abstrakcyjna.h" //

class Glowna //
{
    //POLA
    int pojemnosc;
    std::vector<Abstrakcyjna_ptr> elementy; //

public:

    bool dodaj(Abstrakcyjna_ptr element); //
    bool usun(Abstrakcyjna_ptr element); //

    //
    int pobierzLiczbe();
    int pobierzLaczna();
    float pobierzSrednia();

    std::string toString();



    int getPojemnosc() const; //-

};
typedef std::shared_ptr<Glowna> Glowna_ptr; //




#endif
