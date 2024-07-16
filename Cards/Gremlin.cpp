
#include <iostream>
#include "Gremlin.h"

Gremlin::Gremlin() : Card()
{
    m_stats.m_force = 5;
    m_stats.m_loot = 2;
    m_stats.m_hpLossOnDefeat = 10;
}

void Gremlin::applyEncounter(Player& player) const
{
    if(player.getAttackStreangth() < m_stats.m_force){
        printLossBattle(player.getName(), "Gremlin");
        player.demage(m_stats.m_hpLossOnDefeat);
    } else {
        printWinBattle(player.getName(), "Gremlin");
        player.addCoins(m_stats.m_loot);
        player.levelUp();
    }
}

void Gremlin::printCard(std::ostream& os) const 
{
    printCardDetails(os, "Gremlin");
    printMonsterDetails(os, m_stats.m_force, m_stats.m_hpLossOnDefeat, m_stats.m_loot);
    printEndOfCardDetails(os);
}

// std::ostream& operator<<(std::ostream& os, const Gremlin& gremlin)
// {
//     os << "Gremlin";
//     return os;
// }