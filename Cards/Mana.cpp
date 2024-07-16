
#include "Mana.h"

Mana::Mana() : Card() {}

void Mana::applyEncounter(Player& player) const
{
    if(player.isHealer()){
        player.heal(10);
    }
    printManaMessage(player.isHealer());
}

void Mana::printCard(std::ostream& os) const
{
    printCardDetails(os, "Mana");
    printEndOfCardDetails(os);
}

// std::ostream& operator<<(std::ostream& os, const Mana& mana)
// {
//     mana.printCard(os);
//     return os;
// }