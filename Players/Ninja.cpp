
#include "Player.h"
#include "Ninja.h"
#include "../utilities.h"
#include <iostream>

Ninja::Ninja(const char* name) : Player(std::string(name)) {}

Ninja::Ninja(std::string& name) : Player(name) {}

bool Ninja::isNinja() const
{
    return true;
}
void Ninja::addCoins(int coins)
{
    this->m_coins += (2*coins);
}

void Ninja::printInfo(std::ostream& os) const
{
    printPlayerDetails(os, m_name, "Ninja", m_level, m_force, m_hp, m_coins);
}

std::ostream& operator<<(std::ostream& os, const Ninja& ninja)
{
    ninja.printInfo(os);
    return os;
}