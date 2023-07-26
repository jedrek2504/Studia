#ifndef TOMCZYK_MAGAZYN_OPAKOWANIE_H
#define TOMCZYK_MAGAZYN_OPAKOWANIE_H
#include <iostream>
#include <memory>

class Opakowanie
{
protected:
    int id;

public:
    explicit Opakowanie(int id);

    virtual ~Opakowanie();

    int getId() const;

    void setId(int id);

    virtual std::string opis();
    virtual double objetosc()=0;
};
typedef std::shared_ptr<Opakowanie> OpakowaniePtr;
#endif //TOMCZYK_MAGAZYN_OPAKOWANIE_H
