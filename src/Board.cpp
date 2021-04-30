#include "Board.h"

Board::Board(){}

Board::~Board(){}

void Board::addTile(shared_ptr<Tile> tile)
{
    this->board.push_back(tile);
}

int Board::getLength()
{
    return this->board.size();
}

void Board::printBoard()
{
    
}

int Board::getRow(Row row)
{
    return 0;
}