
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
    string playerName;
    int score;
public:
    Player(string playerName);
    ~Player();
    string getPlayerName();
    int getScore();
    void addScore();
    shared_ptr<LinkedList> getHand();
};

#endif // ASSIGN2_PLAYER_H