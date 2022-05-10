#ifndef _PASAZERSKI_H
#define _PASAZERSKI_H
#include <iostream>
#include <memory>
#include "Wagon.h"

class Pasazerski :public Wagon
{
    int liczbaPasazerow;
public:
    std::string toString();

    Pasazerski(int masaDopuszczalna, int liczbaPasazerow);

    int getLiczbaPasazerow() const;
    void setLiczbaPasazerow(int liczbaPasazerow);

    virtual ~Pasazerski();
};
typedef std::shared_ptr<Pasazerski> Pasazerski_ptr;
#endif
