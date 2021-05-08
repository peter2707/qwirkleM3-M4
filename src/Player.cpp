#include "Player.h"


Player::Player(string playerName)
{
}

Player::Player(){}


Player::~Player()
{
}

void Player::setPlayerHand()
{

}

string Player::printHandSave()
{
    return "";
}

shared_ptr<LinkedList> Player::getHand()
{
    return hand;
}

string Player::getName()
{
    return playerName;
}

int Player::getScore(){
    return score;
}