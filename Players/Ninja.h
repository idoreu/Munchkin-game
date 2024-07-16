
#ifndef NINJA_H_
#define NINJA_H_

#include "Player.h"
#include <ostream>

class Ninja : public Player {
    public:
    Ninja(const char* name);
    Ninja(std::string& name);
    
    bool isNinja() const override;
    void addCoins(int coins) override;

    void printInfo(std::ostream& os) const override;
    friend std::ostream& operator<<(std::ostream& os, const Ninja& ninja);
};


#endif