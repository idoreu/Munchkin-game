
#include <iostream>
#include "Merchant.h"

Merchant::Merchant() : Card() {}


void Merchant::printCard(std::ostream& os) const
{
    printCardDetails(os, "Merchant");
    printEndOfCardDetails(os);
}

bool Merchant::isMerchant() const{
    return true;
}

void Merchant::applyEncounter(Player& player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    int merch;
    std::string line;
    bool inValid = true;
    while(inValid){
        std::getline(std::cin, line);
        try {
            merch = std::stoi(line);
            inValid = false;
            if(merch < 0 || 2 < merch){
                inValid = true;
            }
        }
        catch (std::invalid_argument&) {
            printInvalidInput();
        } catch (std::out_of_range&) {
            printInvalidInput();
        }
    }
    if(merch == 1){
        if(player.getCoins() < 5){
            printMerchantInsufficientCoins(std::cout);
        } else {
            player.pay(5);
            player.heal(1);
            printMerchantSummary(std::cout, player.getName(), 1, 5);
        }
    } else if(merch == 2){
        if(player.getCoins() < 10){
            printMerchantInsufficientCoins(std::cout);
        } else {
            player.pay(10);
            player.buff(1);
            printMerchantSummary(std::cout, player.getName(), 2, 10);
        }
    } else {
        printMerchantSummary(std::cout, player.getName(), 0, 0);
    }
}

// std::ostream& operator<<(std::ostream& os, const Merchant& merchant)
// {
//     os << "Merchant";
//     return os;
// }