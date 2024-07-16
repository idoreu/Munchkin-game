
#ifndef DRAGON_H_
#define DRAGON_H_

#include "Card.h"

class Dragon : public Card 
{
    public:
    Dragon();

    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;
    // friend std::ostream& operator<<(std::ostream& os, const Dragon& dragon);
};

#endif