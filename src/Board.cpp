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
    for(uint32_t i = 0; i < BOARD_SIZE; i++)
    {
        for(uint32_t j = 0; j < BOARD_SIZE; j++)
        {
            for(int k = 0; k < this->board.size(); k++)
            {
                Tile* curTile = this->board.at(k);
                Row row = curTile->row;
                Col col = curTile->col;
                if(getRow(row) == i && col == j)
                {
                    std::cout << curTile->shape << curTile->colour << std::endl;
                }
            }
        }
    }
}

int Board::getRow(Row row)
{
    return 0;
}