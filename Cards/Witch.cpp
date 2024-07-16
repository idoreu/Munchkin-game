
#include <iostream>
#include "Witch.h"

Witch::Witch() : Card()
{
    m_stats.m_force = 11;
    m_stats.m_loot = 2;
    m_stats.m_hpLossOnDefeat = 10;
}

void Witch::applyEncounter(Player& player) const
{
    if(player.getAttackStreangth() < m_stats.m_force){
        printLossBattle(player.getName(), "Witch");
        player.demage(m_stats.m_hpLossOnDefeat);
        player.buff(-1);
    } else {
        printWinBattle(player.getName(), "Witch");
        player.addCoins(m_stats.m_loot);
        player.levelUp();
    }
}

void Witch::printCard(std::ostream& os) const
{
    printCardDetails(os, "Witch");
    printMonsterDetails(os, m_stats.m_force, m_stats.m_hpLossOnDefeat, m_stats.m_loot);
    printEndOfCardDetails(os);
}

// std::ostream& operator<<(std::ostream& os, const Witch& witch)
// {
//     os << "Witch";
//     return os;
// }