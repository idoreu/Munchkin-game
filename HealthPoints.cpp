

#include "HealthPoints.h"
#include <iostream>

//--Constructors

HealthPoints::HealthPoints(int health) : m_maxHealth(health), m_currHealt(health) 
{
    if(health <= 0){
        throw (HealthPoints::InvalidArgument());
    }
}

//--Arithmatic operators:

HealthPoints& HealthPoints::operator+=(const HealthPoints& healthPoints)
{
    m_currHealt += healthPoints.m_currHealt;
    if(m_currHealt >= m_maxHealth){
        m_currHealt = m_maxHealth;
    }
    return *this;
}

HealthPoints operator+(int health, const HealthPoints& only)
{
    HealthPoints temp = only;
    temp += health;
    return temp;
}

HealthPoints& HealthPoints::operator-=(const HealthPoints& healthPoints)
{
    m_currHealt -= healthPoints.m_currHealt;
    if(m_currHealt <= 0){
        m_currHealt = 0;
    }
    return *this;
}

HealthPoints operator-(const HealthPoints& first, const HealthPoints& secound)
{
    HealthPoints temp = first;
    temp -= secound;
    return temp;
}

bool operator==(const HealthPoints& first, const HealthPoints& secound)
{
    if(first.m_currHealt == secound.m_currHealt){
        return true;
    }
    return false;
}

bool operator!=(const HealthPoints& first, const HealthPoints& secound)
{
    if(first == secound){
        return false;
    }
    return true;
}

bool operator<(const HealthPoints& first, const HealthPoints& secound)
{
    if(first.m_currHealt < secound.m_currHealt){
        return true;
    }
    return false;
}

bool operator<=(const HealthPoints& first, const HealthPoints& secound)
{
    if(secound < first){
        return false;
    }
    return true;
}

bool operator>(const HealthPoints& first, const HealthPoints& secound)
{
    if(secound < first){
        return true;
    }
    return false;
}

bool operator>=(const HealthPoints& first, const HealthPoints& secound)
{
    if(first < secound){
        return false;
    }
    return true;
}

std::ostream& operator<<(std::ostream& stream, const HealthPoints& healthPoints)
{
    stream << healthPoints.m_currHealt << '(' << healthPoints.m_maxHealth << ')';
    return stream;
}

