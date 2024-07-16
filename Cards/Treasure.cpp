
#include "Treasure.h"

Treasure::Treasure() : Card() {}

void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(10);
    printTreasureMessage();
}
void Treasure::printCard(std::ostream& os) const
{
    printCardDetails(os, "Treasure");
    printEndOfCardDetails(os);
}

// std::ostream& operator<<(std::ostream& os, const Treasure& treausre)
// {
//     treausre.printCard(os);
//     return os;
// }