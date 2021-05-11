#include "Board.h"

Board::Board()
{
    boardCol = 6;
    boardRow = 6;
    newCol = 6;
    newRow = 6;
}

// Board::Board(std::vector<std::shared_ptr<Tile>> board, int boardRow, int boardCol)
// {

// }

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
    for(int j = 0; j < boardCol; j++)
    {
        printf("%3d", j);
    }
    std::cout << "\n";
    printf("%2c%s\n", ' ',std::string((boardCol*(boardCol/2)+1),'-').c_str());

    for(int i = 0; i < boardRow; i++)
    {
        std::cout << row << " |";
        for(int j = 0; j < boardCol; j++)
        {
            std::cout << tilePosition(row, j) << "|"; 
        }
        std::cout << "\n";
        row++;
    }
}

string Board::tilePosition(char row, int col)
{
    string tilePos;
    for(uint32_t k = 0; k < this->board.size(); k++)
    {
        shared_ptr<Tile> tile = this->board.at(k);
        Row tileRow = tile->row;
        Col tileCol = tile->col; 

        if(tileRow == row && tileCol == col)
        {
            tilePos = tile->colour + std::to_string(tile->shape);
        }   
    }
    if(tilePos.empty())
    {
        tilePos = "  ";
    }
    return tilePos;
}

bool Board::placeTile(shared_ptr<Tile> tile)
{
    bool placed = false;
    if(this->board.empty())
    {
        addTile(tile);
        expandBoard(tile->row, tile->col);
        //player->addScore(1);
        placed = true;
    }
    else
    {
        if(!exist(tile->row, tile->col))
        {
            addTile(tile);
            expandBoard(tile->row, tile->col);
            placed = true;
        }
    }
    return placed;
}

void Board::expandBoard(Row rowTile, Col colTile)
{
    // Minus A from the current Row entered gives you an int that is useable
    int row = rowTile - 'A';
    // Expands the Row of the board
    if(row == (this->boardRow -1))this->boardRow++;

    // Expands the Col of the board
    if(colTile == (this->boardCol -1))this->boardCol++;

    this->setNewRow(this->boardRow++);
    this->setNewCol(this->boardCol++);
}

void Board::setNewRow(int newRow){
    this->newRow = newRow;
}

void Board::setNewCol(int newCol){
    this->newCol = newCol;
}

int Board::getNewRow(){
    return newRow;
}

int Board::getNewCol(){
    return newCol;
}

bool Board::exist(Row tileRow, Col tileCol)
{
    // Checks if the a tile is placed at the position the user has entered 
    bool exists = false;
    for(uint32_t k = 0; k < this->board.size(); k++)
    {
        Row row = this->board.at(k)->row;
        Col col = this->board.at(k)->col;

        if(tileCol == col && tileRow == row)
        {
            exists = true;
        }
    }
    return exists;
}

string Board::printBoardSave()
{
    string board;
    for(uint32_t i = 0; i < this->board.size(); i++)
    {
        shared_ptr<Tile> tile = this->board.at(i);
        if(i == (this->board.size() - 1))
        {
            board+= tile->colour;
            board+= std::to_string(tile->shape);
            board+= "@";
            board+= tile->row;
            board+= std::to_string(tile->col);
        }
        else
        {   
            board+= tile->colour;
            board+= std::to_string(tile->shape);
            board+= "@";
            board+= tile->row;
            board+= std::to_string(tile->col);
            board+= ", ";
        }
    }
    return board;
}   

int Board::calculatePoints(int boardRow, int boardCol){
    int score = 1;
    // int tempRow = boardRow;
    // int tempCol = boardCol;
    

    //check right
    // if (boardRow <= BOARD_SIZE && boardCol <= BOARD_SIZE) {
    //     while (array[tempRow][tempCol + 1]->colour != ' ') {
    //         score++;
    //         tempCol = tempCol + 1;
    //         if(tempRow < 1 || tempCol >= BOARD_SIZE - 1){
    //             break;
    //         }

    //     }
    //     tempRow = boardRow;
    //     tempCol = boardCol;
    // }
    
    // //check left
    // if (boardRow >= 1 && boardCol >= 1) {
    //     while (array[tempRow][tempCol - 1]->colour != ' ' &&  array[tempRow][tempCol + 1]->shape != -1) {
    //         score++;
    //         tempCol = tempCol - 1;

    //     }

    //     tempRow = boardRow;
    //     tempCol = boardCol;
    // }

    // //check down
    // if (boardRow >= 1 && boardCol >= 1) {
    //     while (array[tempRow - 1][tempCol]->colour != ' ' &&  array[tempRow - 1][tempCol - 1]->shape != -1) {
    //         score++;
    //         tempRow = tempRow - 1;

    //     }

    //     tempRow = boardRow;
    //     tempCol = boardCol;
    // }

    // //check up
    // if (boardRow >=1 && boardCol >= 1) {
    //     while (array[tempRow + 1][tempCol]->colour != ' ' &&  array[tempRow - 1][tempCol - 1]->shape == -1) {
    //         score++;
    //         tempRow = tempRow + 1;

    //     }

    //     tempRow = boardRow;
    //     tempCol = boardCol;
    // }


    // if (score >= 6){
    //     score+= 6;
    //     std::cout << "Qwirkle!!!" << std::endl;
    // }
    //std::cout << "You got: " << score << " points" << std::endl;

    score++;
    return score;
}