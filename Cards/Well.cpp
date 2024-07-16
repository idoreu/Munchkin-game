
#include "Well.h"

Well::Well() : Card() {}

void Well::applyEncounter(Player& player) const
{
    if(!player.isNinja()){
        player.demage(10);
    }
    printWellMessage(player.isNinja());
}
void Well::printCard(std::ostream& os) const
{
    printCardDetails(os, "Well");
    printEndOfCardDetails(os);
}
// std::ostream& operator<<(std::ostream& os, const Well& well)
// {
//     os << "Well";
//     return os;
// }