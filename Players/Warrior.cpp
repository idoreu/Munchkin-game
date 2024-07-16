

#include "Player.h"
#include "Warrior.h"
#include "../utilities.h"

Warrior::Warrior(const char* name) : Player(std::string(name)) {}

Warrior::Warrior(std::string& name) : Player(name) {}

bool Warrior::isWarrior() const
{
    return true;
}
int Warrior::getAttackStreangth() const
{
    return (2*m_force) + m_level;
}

void Warrior::printInfo(std::ostream& os) const
{
    printPlayerDetails(os, m_name, "Warrior", m_level, m_force, m_hp, m_coins);
}

std::ostream& operator<<(std::ostream& os, const Warrior& warrior)
{
    warrior.printInfo(os);
    return os;
}