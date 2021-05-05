#include "Board.h"

Board::Board()
{

}

Board::Board(std::vector<std::shared_ptr<Tile>> board, int boardRow, int boardCol)
{

}

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
    char row = 'A';
    printf("%2c", ' ');
    for(int j = 0; j < boardRow; j++)
    {
        printf("%3d", j);
    }
    std::cout << std::endl;
    printf("%2c%s\n", ' ',std::string(79,'-').c_str());

    for(int i = 0; i < boardRow; i++)
    {
        std::cout << row << " |";
        for(int j = 0; j < boardRow; j++)
        {
            for(uint32_t k = 0; k < this->board.size(); k++)
            {
                shared_ptr<Tile> tile = this->board.at(k);
                Row tileRow = tile->row;
                Col tileCol = tile->col; 

                if(tileRow == row && tileCol == j)
                {
                    printf("%c%d", tile->colour , tile->shape);
                }   
            }
            printf("%3s", "|");
        }
        std::cout << std::endl; 
        row++;
    }
}

int Board::getRow(Row row)
{
    return 0;
}