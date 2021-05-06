
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
#include <regex>
#include <climits>

using std::string;

class Engine
{
public:
    Engine();
    ~Engine();
    void startGame(Player* playerList[], int numPlayer);
    // void loadGame(Board board, Player playerList[]);
    void playTile(Tile tile);
    void saveGame(string fileName);
    void loadGame(string fileName);
    
private:
    // Board
    Board* board;
    // Players
    Player* players[PLAYERS];
    // Bag
    shared_ptr<LinkedList> bag;
    // Current Player
    string currentPlayer;

    // Shuffles game tilebag at the start of the game
    void shuffleBag();

    // Gives tiles to players until their bag is full
    void giveTiles();

    // Runs the game until there is no more tiles in the bag or users quite the game
    void gameRun();

    // Place tile to boards
    void placeTile(Player* curPlayer, string tilePlaced, string location);
};

#endif // ASSIGN2_ENGINE_H