 
#ifndef HEALTH_POINTS_H_
#define HEALTH_POINTS_H_

#include <iostream>

#define DEFAULT_HEALTH 100


class HealthPoints {
    public:
    //--Constructors:
    HealthPoints(int health = DEFAULT_HEALTH);
    HealthPoints(const HealthPoints&) = default;
    ~HealthPoints() = default;
    HealthPoints& operator=(const HealthPoints&) = default;
    //--Arithmetical operators:
    HealthPoints& operator+=(const HealthPoints&);
    HealthPoints& operator-=(const HealthPoints&);
    //--Boolean operators:
    friend bool operator==(const HealthPoints&, const HealthPoints&);
    friend bool operator<(const HealthPoints&, const HealthPoints&);
    friend std::ostream& operator<<(std::ostream&, const HealthPoints&);
    class InvalidArgument {};

    private:
    int m_maxHealth;
    int m_currHealt;
};

//HealthPoints operator+(const HealthPoints& first, const HealthPoints& secound);
HealthPoints operator-(const HealthPoints& first, const HealthPoints& secound);
bool operator!=(const HealthPoints& first, const HealthPoints& secound);
bool operator<=(const HealthPoints& first, const HealthPoints& secound);
bool operator>(const HealthPoints& first, const HealthPoints& secound);
bool operator>=(const HealthPoints& first, const HealthPoints& secound);
HealthPoints operator+(int health, const HealthPoints& only);


#endif