
#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include "LinkedList.h"
#include <iostream>
#include <memory>
#include <string>

using std::shared_ptr;
using std::string;  

class Player
{
private:
    shared_ptr<LinkedList> hand;
    
public:
    string playerName;
    int score;
    void setPlayerHand(shared_ptr<LinkedList> playerHand);
    Player();
    Player(string playerName);
    ~Player();
    void addScore(int score);
    string getHand();
    string printHandSave();
    string getName();
    int getScore();
};

#endif // ASSIGN2_PLAYER_H