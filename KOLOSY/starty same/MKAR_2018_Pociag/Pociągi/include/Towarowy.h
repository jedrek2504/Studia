//
// Created by pobi on 13.12.18.
//

#ifndef PROJECT_TOWAROWY_H
#define PROJECT_TOWAROWY_H


#include <Wagon.h>

class Towarowy : public Wagon {
int pojemnoscSkrzyni;
public:
    Towarowy(int masaDopuszczalna, int pojemnoscSkrzyni);
    std::string toString();
    int getPojemnoscSkrzyni() const;
};


#endif //PROJECT_TOWAROWY_H
