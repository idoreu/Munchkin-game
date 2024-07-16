
#include <string>
#include "Player.h"
#include "../utilities.h"

Player::Player(std::string name, int maxHp, int force) : m_name(name), m_level(1), m_coins(10), 
    m_maxHP(maxHp), m_hp(maxHp), m_force(force) {}

void Player::levelUp()
{
    m_level +=1;
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(int buffPoints)
{
    m_force += buffPoints;
    if(m_force <= 0){
        m_force = 0;
    }
}


void Player::demage(int demagePoints)
{
    if(demagePoints >= 0){
        m_hp -= demagePoints;
        if(m_hp <= 0){
            m_hp = 0;
        }
    } else {
        m_hp += demagePoints;
        if(m_hp <= 0){
            m_hp = 0;
        }  
    }
}

bool Player::isKnockedOut() const
{
    return !m_hp;
}
bool Player::pay(int cost)
{
    if(m_coins - cost < 0){
        return false;
    }
    m_coins -= cost;
    return true;
}

void Player::heal(int healthPoints)
{
    m_hp += healthPoints;
    if(m_hp >= m_maxHP){
        m_hp = m_maxHP;
    }
}
void Player::addCoins(int coins)
{
    m_coins += coins;
}

int Player::getAttackStreangth() const
{
    return m_force + m_level;
}

bool Player::isHealer() const
{
    return false;
}
bool Player::isNinja() const
{
    return false;
}
bool Player::isWarrior() const
{
    return false;
}

std::string Player::getName() const{
    return m_name;
}

int Player::getHealth() const
{
    return m_hp;
}

int Player::getCoins() const
{
    return m_coins;
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    player.printInfo(os);
    return os;
}