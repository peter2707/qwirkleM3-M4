
#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include <iostream>
#include <vector>
#include "Tile.h"
#include <memory>
#include <string>
#include "Player.h"
#include "Type.h"

using std::vector;
using std::shared_ptr;
using std::string;

class Board
{
    public:
        Board();
        Board(std::vector< std::shared_ptr<Tile> > board, int boardRow, int boardCol);
        ~Board();

        void addTile(shared_ptr<Tile> tile);
        void printBoard();
        int getLength();
        string printBoardSave();
        bool placeTile(shared_ptr<Tile> tile);
        int calculatePoints(Row tileRow, Col tileCol);
        int getNewRow();
        int getNewCol();

    private:
        std::shared_ptr<Tile> array[BOARD_SIZE][BOARD_SIZE];
        vector< shared_ptr<Tile> > board;
        int getRow(Row row);
        int boardRow;
        int boardCol;
        int newRow;
        int newCol;
        void setNewRow(int newRow);
        void setNewCol(int newCol);
        string tilePosition(char row, int col);
        bool exist(Row tileRow, Col tileCol);
        void expandBoard(Row rowTile, Col colTile);

};


#endif // ASSIGN2_BOARD_H