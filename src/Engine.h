
#ifndef ASSIGN2_ENGINE_H
#define ASSIGN2_ENGINE_H

#include "Type.h"
#include "LinkedList.h" 
#include "Board.h"
#include "Player.h"
#include <string>

class Engine
{
private:
    Board* board;
    Player players[PLAYERS];
    shared_ptr<LinkedList> bag;

    void shuffleBag();
public:
    Engine();
    ~Engine();
    void startGame(Player playerList[], int numPlayer);
    void loadGame(std::string filename);
    void playTile(Tile tile);
};

#endif // ASSIGN2_ENGINE_H