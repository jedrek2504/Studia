#include "model/TicketType.h"
#include <sstream>

//getter
DiscountType TicketType::getDiscountType() const {
    return discountType;
}

//setter
void TicketType::setDiscountType(DiscountType discountType) {
    TicketType::discountType = discountType;
}

//NormalTicket other methods
std::string NormalTicket::getInfo() const {
    return "normalny";
}

float NormalTicket::getRealCost(float price) const {
    return price;
}

//DiscountedTicket other methods
std::string DiscountedTicket::getInfo() const {
    std::stringstream chain;
    chain<<"ulgowy , Typ znizki: ";
    if (getDiscountType() == child)
    {
        chain<<"dziecieca.";
    }
    if (getDiscountType() == student)
    {
        chain<<"studencka.";

    }
    if (getDiscountType() == rentist)
    {
        chain<<"emerycka.";
    }
    return chain.str();
}

float DiscountedTicket::getRealCost(float price) const {
    if (getDiscountType() == child)
    {
        return price * 0.5;
    }
    if (getDiscountType() == student)
    {
        return price * 0.7;
    }
    if (getDiscountType() == rentist)
    {
        return price * 0.8;
    }
    return 0;
}



