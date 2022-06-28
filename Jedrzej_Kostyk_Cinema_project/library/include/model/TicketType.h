#ifndef TICKETTYPE_H
#define TICKETTYPE_H

#include <string>

enum DiscountType{ child , student , rentist}; //enumeracja - typy znizek (C-50% , S-30% , R-20%)

class TicketType {

    DiscountType discountType;

public:

    //getter
    DiscountType getDiscountType() const;

    //setter
    void setDiscountType(DiscountType discountType);

    //other methods
    virtual float getRealCost(float price) const = 0; // oblicz rzeczywista cene (po uwzglednieniu odpowiedniej znizki)

    virtual std::string getInfo() const = 0; //wyswietla typ biletu i ew typ znizki

};

class NormalTicket : public TicketType {
public:
    float getRealCost(float price) const override;
    std::string getInfo() const override;
};

class DiscountedTicket : public TicketType {
public:
    float getRealCost(float price) const override;
    std::string getInfo() const override;
};

#endif //TICKETTYPE_H
