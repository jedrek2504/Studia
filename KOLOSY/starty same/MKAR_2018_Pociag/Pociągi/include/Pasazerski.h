//
// Created by pobi on 13.12.18.
//

#ifndef PROJECT_PASAZERSKI_H
#define PROJECT_PASAZERSKI_H


#include <Wagon.h>

class Pasazerski : public Wagon {
int liczbaPasazerow;
public:
    Pasazerski(int masaDopuszczalna, int liczbaPasazerow);
    int getLiczbaPasazerow() const;
    std::string toString();
};


#endif //PROJECT_PASAZERSKI_H
