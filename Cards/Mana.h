
#ifndef MANA_H_
#define MANA_H_

#include "Card.h"

class Mana : public Card
{
    public:
    Mana();
    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;
    // friend std::ostream& operator<<(std::ostream& os, const Mana& mana);
};
#endif