#ifndef START_STATEK_LADUNEK_H
#define START_STATEK_LADUNEK_H
#include <iostream>
#include <memory>

class Ladunek
{
    std::string nazwa;
public:
    Ladunek(std::string nazwa);

    virtual int obliczMase()=0;
    virtual std::string toString()=0;

    const std::string &getNazwa() const;
    void setNazwa(const std::string &nazwa);

    virtual ~Ladunek();
};
typedef std::shared_ptr<Ladunek> Ladunek_ptr;

#endif //START_STATEK_LADUNEK_H
