
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
    void setPlayerHand();
    Player();
    Player(string playerName);
    ~Player();
    void addScore(int score);
    shared_ptr<LinkedList> getHand();
};

#endif // ASSIGN2_PLAYER_H