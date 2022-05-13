#ifndef TOMCZYK_MAGAZYN_BECZKA_H
#define TOMCZYK_MAGAZYN_BECZKA_H
#include <iostream>
#include <memory>
#include "Opakowanie.h" //

class Beczka :public Opakowanie  //
{
    //POLE:
    std::string promien;
    double wysokosc;

public:
    Beczka(int id, const std::string &promien, double wysokosc);

    virtual ~Beczka();

    const std::string &getPromien() const;

    void setPromien(const std::string &promien);

    double getWysokosc() const;

    void setWysokosc(double wysokosc);

    std::string opis() override;
    double objetosc() override;



};
typedef std::shared_ptr<Beczka> Beczka_ptr;
#endif //TOMCZYK_MAGAZYN_BECZKA_H
