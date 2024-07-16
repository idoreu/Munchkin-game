//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"
#include <iostream>

enum class CardType {Witch, Gremlin, Dragon, Mana, Barfight, Well, Treasure, Merchant}; // The type of the Card

struct CardStats{
    int m_force;  // The force of the monster
    int m_hpLossOnDefeat; // The amount of hp you lose when losing the battle
    int m_cost; // The cost of a "Buff/Heal" card
    int m_heal; // The amount of HP you get when buying a "HEAL" card
    int m_buff; // The amount of force you get when buying a "BUFF" card
    int m_loot; // The profit you get when winning a battle or when getting a "Treasure" card


    explicit CardStats(int force = 0, int hpLoss = 0, int cost = 0, int heal = 0, int buff = 0, int loot = 0) :
        m_force(force), m_hpLossOnDefeat(hpLoss), m_cost(cost), m_heal(heal), m_buff(buff), m_loot(loot) {} 
};

class Card {
public:
    virtual ~Card() = default;
    explicit Card(): m_stats() {}

    virtual bool isMerchant() const {return false;}

    virtual void applyEncounter(Player& player) const = 0;
    virtual void printCard(std::ostream& os) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

protected:
    CardStats m_stats;
private:
    //CardType m_effect;
};


#endif //EX2_Card_H
