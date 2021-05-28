#include "Player.h"


Player::Player(std::string playerName){
    this->playerName = playerName;
    this->score = 0;
}

Player::Player(){
    this->score = 0;
}


Player::~Player(){
}

void Player::setPlayerHand(std::shared_ptr<LinkedList> playerHand){
    this->hand = playerHand;
}

std::string Player::printHandSave(){
    return "";
}

std::shared_ptr<LinkedList> Player::getHand(){
    return hand;
}

std::string Player::getHandColor(){
    std::string printHand;
    std::string colorCode = COLOR_BLACK;
    std::string shapeCode;
    
    for(int i = 0; i < hand->size(); i++) {
        if (hand->get(i)->colour == RED) colorCode = COLOR_RED;
        else if (hand->get(i)->colour == ORANGE) colorCode = COLOR_ORANGE;
        else if (hand->get(i)->colour == YELLOW) colorCode = COLOR_YELLOW;
        else if (hand->get(i)->colour == GREEN) colorCode = COLOR_GREEN;
        else if (hand->get(i)->colour == BLUE) colorCode = COLOR_BLUE;
        else if (hand->get(i)->colour == PURPLE) colorCode = COLOR_PURPLE;

        if (hand->get(i)->shape == CIRCLE) shapeCode = SHAPE_CIRCLE;
        else if (hand->get(i)->shape == STAR_4) shapeCode = SHAPE_STAR_4;
        else if (hand->get(i)->shape == DIAMOND) shapeCode = SHAPE_DIAMOND;
        else if (hand->get(i)->shape == SQUARE) shapeCode = SHAPE_SQUARE;
        else if (hand->get(i)->shape == STAR_6) shapeCode = SHAPE_STAR_6;
        else if (hand->get(i)->shape == CLOVER) shapeCode = SHAPE_CLOVER;

        if(i == (hand->size() - 1)){
            printHand += colorCode + hand->get(i)->colour + shapeCode + COLOR_RESET;
        }else{
            printHand += colorCode + hand->get(i)->colour + shapeCode + COLOR_RESET + ",";
        }
    }
    return printHand;
}

std::string Player::getHandString(){
    std::string printHand;
    for(int i = 0; i < hand->size(); i++) {
        if(i == (hand->size() - 1)){
            printHand += hand->get(i)->colour + std::to_string(hand->get(i)->shape);
        }else{
            printHand += hand->get(i)->colour + std::to_string(hand->get(i)->shape) + ",";
        }
    }
    return printHand;
}

std::string Player::getName(){
    return playerName;
}

void Player::setName(std::string name){
    this->playerName = name;
}

int Player::getScore(){
    return score;
}

void Player::addScore(int score){
    this->score = score;
}