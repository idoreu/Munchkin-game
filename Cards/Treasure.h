
#ifndef TREASURE_H_
#define TREASURE_H_

#include "Card.h"

class Treasure : public Card
{
    public:
    Treasure();

    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;
    // friend std::ostream& operator<<(std::ostream& os, const Treasure& merchant);
};

#endif