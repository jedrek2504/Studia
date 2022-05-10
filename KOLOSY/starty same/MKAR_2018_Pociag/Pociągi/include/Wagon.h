//
// Created by pobi on 13.12.18.
//

#ifndef PROJECT_WAGON_H
#define PROJECT_WAGON_H

#include <string>

class Wagon {
int masaDopuszczalna;
public:
    Wagon(int masaDopuszczalna);
    virtual std::string toString();
    //getter
    int getMasaDopuszczalna() const;
};


#endif //PROJECT_WAGON_H
