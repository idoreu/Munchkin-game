
#include "Barfight.h"

Barfight::Barfight() : Card() {}

void Barfight::applyEncounter(Player& player) const
{
    if(!player.isWarrior()){
        player.demage(10);
    }
    printBarfightMessage(player.isWarrior());
}
void Barfight::printCard(std::ostream& os) const
{
    printCardDetails(os, "Barfight");
    printEndOfCardDetails(os);
}