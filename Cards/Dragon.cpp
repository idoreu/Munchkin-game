
#include "Dragon.h"

Dragon::Dragon() : Card() 
{
    m_stats.m_force = 25;
    m_stats.m_loot = 1000;

}

void Dragon::applyEncounter(Player& player) const
{
    if(player.getAttackStreangth() < m_stats.m_force){
        printLossBattle(player.getName(), "Dragon");
        player.demage(player.getHealth());
    } else {
        printWinBattle(player.getName(), "Dragon");
        player.addCoins(m_stats.m_loot);
        player.levelUp();
    }
}

void Dragon::printCard(std::ostream& os) const
{
    printCardDetails(os, "Dragon");
    printMonsterDetails(os, m_stats.m_force, m_stats.m_hpLossOnDefeat, m_stats.m_loot, true);
    printEndOfCardDetails(os);
}

