//
// Created by pobi on 13.12.18.
//

#ifndef PROJECT_POCIAG_H
#define PROJECT_POCIAG_H

#include <memory>
#include <vector>
class Wagon;
typedef std::shared_ptr<Wagon>Wagon_ptr;

class Pociag {
int masaMaksymalna;
std::vector<Wagon_ptr> wagony;
public:
    Pociag(int masaMaksymalna);
    ~Pociag();
    std::string toString();
    bool dodajWagon(Wagon_ptr);
    void usunWagon(Wagon_ptr);
    int pobierzLiczbeWagonow();
    int pobierzLacznaMaseDopuszczalnaWagonow();
    float pobierzSredniaMaseDopuszczalnaWagonow();
    int getMasaMaksymalna() const;

};
typedef std::shared_ptr <Pociag> Pociag_ptr;

#endif //PROJECT_POCIAG_H
