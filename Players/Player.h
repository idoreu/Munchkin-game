
#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

//num class PlayerType { Warrior, Healer, Ninja};

class Player{
    public:
    Player(std::string name, int maxHp = 100, int force = 5);
    virtual ~Player() = default;
    //
    std::string getName() const;
    int getCoins() const;
    int getHealth() const;
    void levelUp();
    int getLevel() const;
    void buff(int buffPoints);
    void demage(int demagePoints);
    bool isKnockedOut() const;
    bool pay(int cost);
    //
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    virtual void printInfo(std::ostream& os) const = 0;
    virtual void addCoins(int coins);
    virtual void heal(int healthPoints);
    virtual int getAttackStreangth() const;
    virtual bool isWarrior() const;
    virtual bool isNinja() const;
    virtual bool isHealer() const;

    protected:
    std::string m_name;//probably gonna replace with string
    int m_level;
    int m_coins;
    int m_maxHP;
    int m_hp;
    int m_force;
};



#endif