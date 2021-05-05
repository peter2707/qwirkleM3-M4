
#ifndef ASSIGN2_BOARD_H
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
        Board(std::vector<std::shared_ptr<Tile>> board, int boardRow, int boardCol);
        ~Board();

        void addTile(shared_ptr<Tile> tile);
        void printBoard();
        int getLength();

    private:
        vector< shared_ptr<Tile> > board;
        int getRow(Row row);
        int boardRow;
        int boardCol;

};


#endif // ASSIGN2_BOARD_H