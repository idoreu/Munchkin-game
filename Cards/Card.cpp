
#include <string>
#include "../utilities.h"
#include "../Players/Player.h"
#include "Card.h"
#include <ostream>


std::ostream& operator<<(std::ostream& os, const Card& card)
{
    card.printCard(os);
    return os;
}