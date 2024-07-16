
#ifndef WITCH_H_
#define WITCH_H_

#include "Card.h"

class Witch : public Card 
{
    public:
    Witch();

    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;
    // friend std::ostream& operator<<(std::ostream& os, const Witch& witch);
};

#endif