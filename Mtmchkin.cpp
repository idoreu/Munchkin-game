
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "Mtmchkin.h"
#include <queue>
#include <deque>
#include <sstream>
#include <limits>
#include "Players/Player.h"
#include "Players/Warrior.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Cards/Card.h"
#include "Cards/Gremlin.h"
#include "Cards/Witch.h"
#include "Cards/Dragon.h"
#include "Cards/Merchant.h"
#include "Cards/Barfight.h"
#include "Cards/Well.h"
#include "Cards/Mana.h"
#include "Cards/Treasure.h"
#include "Exception.h"

bool validName(std::unique_ptr<Player> players[6], int max, std::string& name){
    if(name.empty()){
        return false;
    }
    for(char c : name){
        if(!isalpha(c)){
            return false;
        }
    }
    for(int i = 0; i < max; ++i){
        if(name == players[i]->getName()){
            return false;
        }
    }
    return true;
}

bool validClass(std::string& card){
    if(card == "Warrior"){
        return true;
    } else if(card == "Healer"){
        return true;
    } else if(card == "Ninja"){
        return true;
    }
    return false;
}

bool validCard(std::string& card){
    if(card == "Gremlin"){
        return true;
    } else if(card == "Witch"){
        return true;
    } else if(card == "Dragon"){
        return true;
    } else if(card == "Merchant"){
        return true;
    } else if(card == "Treasure"){
        return true;
    } else if(card == "Well"){
        return true;
    } else if(card == "Barfight"){
        return true;
    } else if(card == "Mana"){
        return true;
    }else {
        return false;
    }
}

std::unique_ptr<Player> iniciatePlayer(std::string& name, std::string& playerType){
    if(playerType == "Warrior"){
        return std::unique_ptr<Player>(new Warrior(name));
    } else if(playerType == "Ninja"){
        return std::unique_ptr<Player>(new Ninja(name));
    }
    return std::unique_ptr<Player>(new Healer(name));
}

void createDeck(std::queue<std::shared_ptr<Card>>& deck, std::ifstream& source)
{
    if(!source){
        throw(DeckFileNotFound());
    }
    int row = 0;
    std::string line;
    while(!source.eof() && std::getline(source, line)){
        ++row;
        if(line == "Gremlin"){
            deck.push(std::make_shared<Gremlin>());
        } 
        else if(line == "Witch"){
            deck.push(std::make_shared<Witch>());
        } 
        else if(line == "Dragon"){
            deck.push(std::make_shared<Dragon>());
        } 
        else if(line == "Merchant"){
            deck.push(std::make_shared<Merchant>());
        }
        else if(line == "Treasure"){
            deck.push(std::make_shared<Treasure>());
        }
        else if(line == "Barfight"){
            deck.push(std::make_shared<Barfight>());
        } 
        else if(line == "Well"){
            deck.push(std::make_shared<Well>());
        }
        else if(line == "Mana"){
            deck.push(std::make_shared<Mana>());
        }
        else {
            throw(DeckFileFormatError(row));
        }
    }
    if(deck.size() < 5){
        throw(DeckFileInvalidSize());
    }
}



Mtmchkin::Mtmchkin(const std::string &fileName) : 
    m_deck(std::queue<std::shared_ptr<Card>>()),
    m_round(0)
{
    printStartGameMessage();
    for(int i = 0; i < 6; ++i){
        m_leaderBoard[i] = -1;
        m_inGame[i] = false;
    }
    //__________________
    std::ifstream source(fileName);
    if(!source.is_open()){
        throw(DeckFileNotFound());
    }
    if(source.tellg() == std::ifstream::traits_type::eof() || source.eof()){
        throw(DeckFileInvalidSize());
    }
    createDeck(m_deck, source);
    //___
    int size = -1;
    printEnterTeamSizeMessage();
    if(!std::cin){
        throw(DeckFileFormatError(1));
    }
    std::string line;
    int counter = 0, maxTries = 100;
    while(counter < maxTries){
        std::getline(std::cin, line);
        std::istringstream iss(line);
        while(!iss.eof()){
            if(iss >> size){
                if(2 <= size && size <=6){
                    break;
                }
                iss.clear();
                iss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                throw(DeckFileFormatError(1));
            }
        }
        if(2 <= size && size <=6){
            break;
        }
        iss.clear();
        iss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ++counter;
    }
    m_numOfPlayers = size;
    for(int i = 0; i < size; ++i){
        printInsertPlayerMessage();
        std::string name;
        std::string job;
        //std::string line;
        bool inValid = true;
        while(inValid){
            std::cin >> name;
            std::cin >> job;
            inValid = false;
            if(!validClass(job)){
                inValid = true;
                printInvalidClass();
            } else if(!validName(m_players, i, name)){
                inValid = true;
                printInvalidName();
            }
        }
        //std::unique_ptr<Player> player = std::move(iniciatePlayer(name, job));
        m_players[i] = std::move(iniciatePlayer(name, job));
        m_inGame[i] = true;
    }
}

void insertLoser(int arr[6], int k, int max){
    for(int i = max -1; i >= 0; --i){
        if(arr[i] < 0){
            arr[i] = k;
            return;
        }
    }
}

void insertWinner(int arr[6], int k, int max){
    for(int i = 0; i < max ; ++i){
        if(arr[i] < 0){
            arr[i] = k;
            return;
        }
    }
}

void Mtmchkin::playRound()
{
    ++m_round;
    printRoundStartMessage(m_round);
    if(m_deck.empty()){
        return;
    }
    for(int i = 0; i < m_numOfPlayers; ++i){
        if(m_inGame[i]){
            if(m_players[i] == nullptr){
                throw(std::exception());
            }
            printTurnStartMessage(m_players[i]->getName());
            std::shared_ptr<Card> card = m_deck.front();
            m_deck.pop();
            card->applyEncounter(*m_players[i]);
            m_deck.push(card);
            if(m_players[i]->isKnockedOut()){
                insertLoser(m_leaderBoard, i, m_numOfPlayers);
                m_inGame[i] = false;
            } else if(m_players[i]->getLevel() == 10){
                insertWinner(m_leaderBoard, i, m_numOfPlayers);
                m_inGame[i] = false;
            }
            if(isGameOver()){
                printGameEndMessage();
            }
        }
    }
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_round;
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int save = 0;
    for(int i = 0; i <m_numOfPlayers; ++i){
        if(m_leaderBoard[i] >= 0){
            printPlayerLeaderBoard(i+1, *m_players[m_leaderBoard[i]]);
        } else{  
            for(int j = save; j < m_numOfPlayers; ++j){
                if(m_inGame[j]){
                    printPlayerLeaderBoard(i+1, *m_players[j]);
                    ++save;
                    break;
                }
            }
        }
    }
}

bool Mtmchkin::isGameOver() const
{
    for(int i = 0; i < m_numOfPlayers; ++i){
        if(m_inGame[i]){
            return false;
        }
    }
    return true;
}