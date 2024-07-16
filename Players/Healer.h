
#ifndef HEALER_h_
#define HEALER_h_

#include"Player.h"
#include <ostream>

class Healer : public Player {
    public:
    Healer(const char* name);
    Healer(std::string& name);
    bool isHealer() const override;
    void heal(int healthPoints) override;
    void printInfo(std::ostream& os) const override;
    friend std::ostream& operator<<(std::ostream& os, const Healer& healer);
};


#endif