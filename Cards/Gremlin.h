

#ifndef GREMLIN_H_
#define GREMLIN_H_

#include "Card.h"

class Gremlin : public Card 
{
    public:
    Gremlin();

    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;
    // friend std::ostream& operator<<(std::ostream& os, const Gremlin& gremlin);
};

#endif