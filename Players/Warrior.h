
#ifndef WARRIOR_H_
#define WARRIOR_H_

#include "Player.h"
#include <ostream>

class Warrior : public Player {
    public:
    Warrior(const char* name);
    Warrior(std::string& name);

    bool isWarrior() const override;
    int getAttackStreangth() const override;
    void printInfo(std::ostream& os) const override;

    friend std::ostream& operator<<(std::ostream& os, const Warrior& warrior);
};


#endif