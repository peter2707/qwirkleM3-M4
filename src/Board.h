
#ifndef ASSIGN2_BORAD_H
#define ASSIGN2_BOARD_H

#include <iostream>
#include <vector>
#include "Tile.h"
#include <memory>

using std::vector;
using std::shared_ptr;

class Board
{
    public:
        Board();
        ~Board();

        void addTile(shared_ptr<Tile> tile);
        void printBoard();
        int getLength();

    private:
        vector<shared_ptr<Tile>> board;
        int getRow(Row row);

};


#endif // ASSIGN2_BOARD_H