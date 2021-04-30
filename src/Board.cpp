#include "Board.h"
#include <iostream>

Board::Board(){}

Board::~Board(){}

void Board::addTile(Tile* tile)
{
    this->board.push_back(tile);
}

void Board::printBoard()
{
    
}

int Board::getRow(Row row)
{
    return 0;
}