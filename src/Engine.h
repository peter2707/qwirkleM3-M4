
#ifndef ASSIGN2_ENGINE_H
#define ASSIGN2_ENGINE_H

#include "Type.h"
#include "LinkedList.h" 
#include "Board.cpp"
#include "Player.cpp"
#include <fstream>
#include <string>
#include <sstream>

class Engine
{
private:
    Board* board;
    Player* players[PLAYERS];
    shared_ptr<LinkedList> bag;

    void shuffleBag();
public:
    Engine();
    ~Engine();
    void startGame(Player playerList[], int numPlayer);
    void loadGame(Board bord, Player playerList[]);
    void playTile(Tile tile);
    void loadGame(string fileName);
};

#endif // ASSIGN2_ENGINE_H