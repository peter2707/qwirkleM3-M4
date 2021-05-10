
#ifndef ASSIGN2_ENGINE_H
#define ASSIGN2_ENGINE_H

#include <iostream>
#include <string>
#include "Type.h"
#include "LinkedList.h" 
#include "Board.h"
#include "Player.h"
#include "TileCodes.h"
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include <climits>
#include <random>
#include <vector>
#include <map>

#define NUM_OF_EACH_TILE 2
#define MAX_NUM_OF_TILE 72

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
    void gameRun();
    
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
    void initialiseBag();

    // Gives tiles to players until their bag is full
    void giveTiles();


    void shuffleBag();

    // Runs the game until there is no more tiles in the bag or users quit the game
    

    // Place tile to boards
    bool placeTile(/*Player* curPlayer,*/ string tilePlaced, Row row, Col col);
};

#endif // ASSIGN2_ENGINE_H