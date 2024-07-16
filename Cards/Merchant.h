
#ifndef MERCHANT_H_
#define MERCHANT_H_

#include "../Cards/Card.h"

class Merchant : public Card
{
    public:
    Merchant();

    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;
    // friend std::ostream& operator<<(std::ostream& os, const Merchant& merchant);
    bool isMerchant() const override;
};

#endif