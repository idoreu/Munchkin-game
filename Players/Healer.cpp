

#include "Player.h"
#include "Healer.h"
#include "../utilities.h"

Healer::Healer(const char* name) : Player(std::string(name)) {}

Healer::Healer(std::string& name) : Player(name) {}

bool Healer::isHealer() const
{
    return true;
}
void Healer::heal(int healthPoints)
{
    m_hp += (2*healthPoints);
    if(m_hp >= m_maxHP){
        m_hp = m_maxHP;
    }
}

void Healer::printInfo(std::ostream& os) const
{
    printPlayerDetails(os, m_name, "Healer", m_level, m_force, m_hp, m_coins);
}

std::ostream& operator<<(std::ostream& os, const Healer& healer)
{
    healer.printInfo(os);
    return os;
}