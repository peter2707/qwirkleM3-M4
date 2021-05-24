
#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include "LinkedList.h"
#include <iostream>
#include <memory>
#include <string>


class Player
{
private:
    std::shared_ptr<LinkedList> hand;
    
public:
    Player();
    Player(string playerName);
    ~Player();

    std::string playerName;
    int score;

    std::shared_ptr<LinkedList> getHand();
    void setPlayerHand(std::shared_ptr<LinkedList> playerHand);
    void addScore(int score);
    void setName(string playerName);

    string getHandString();
    string getHandColor();
    string printHandSave();
    string getName();
    
    int getScore();
};

#endif // ASSIGN2_PLAYER_H