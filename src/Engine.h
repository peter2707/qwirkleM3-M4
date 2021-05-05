
#ifndef ASSIGN2_ENGINE_H
#define ASSIGN2_ENGINE_H

#include <iostream>
#include <string>
#include "Type.h"
#include "LinkedList.h" 
#include "Board.h"
#include "Player.h"
#include <fstream>
#include <string>
#include <sstream>

class Engine
{
public:
    Engine();
    ~Engine();
    void startGame(Player playerList[], int numPlayer);
    // void loadGame(Board board, Player playerList[]);
    void playTile(Tile tile);
    void loadGame(string fileName);

private:
    Board* board;
    Player players[PLAYERS];
    shared_ptr<LinkedList> bag;

    void shuffleBag();

};

#endif // ASSIGN2_ENGINE_H