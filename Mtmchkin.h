#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <queue>
#include <deque>
#include <memory>
#include "Players/Player.h"
#include "Cards/Card.h"

class Mtmchkin{
private:
    std::queue<std::shared_ptr<Card>> m_deck;
    std::unique_ptr<Player> m_players[6];
    int m_leaderBoard[6];
    int m_numOfPlayers;
    bool m_inGame[6];
    int m_round;
public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
};



#endif /* MTMCHKIN_H_ */
