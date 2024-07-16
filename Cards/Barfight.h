
#ifndef BAR_FIGHT_H_
#define BAR_FIGHT_H_

#include "Card.h"

class Barfight : public Card
{
    public:
    Barfight();
    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;
    // friend std::ostream& operator<<(std::ostream& os, const Barfight& mana);
};

#endif