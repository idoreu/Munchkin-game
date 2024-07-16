
#ifndef WELL_H_
#define WELL_H_

#include "Card.h"

class Well :public Card
{
    public:
    Well();
    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;
    // friend std::ostream& operator<<(std::ostream& os, const Well& well);
};

#endif