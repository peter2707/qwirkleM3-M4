
#ifndef ASSIGN2_BORAD_H
#define ASSIGN2_BOARD_H

#include <vector>
#include "Tile.h"

using std::vector;


class Board
{
    public:
        Board();
        ~Board();

        void addTile(Tile* tile);
        void printBoard();

    private:
        vector<Tile*> board;
        int getRow(Row row);

};


#endif // ASSIGN2_BOARD_H