#include "Board.h"

Board::Board(){
    boardCol = 6;
    boardRow = 6;
}

Board::~Board(){}

void Board::addTile(shared_ptr<Tile> tile){
    this->board.push_back(tile);
}

int Board::getLength(){
    return this->board.size();
}

void Board::printBoard(){
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

bool Board::placeTile(shared_ptr<Tile> tile){
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
        if(!exist(tile->row, tile->col) && validMove(tile))
        {
            addTile(tile);
            expandBoard(tile->row, tile->col);
            placed = true;
        }
    }
    return placed;
}

void Board::expandBoard(Row rowTile, Col colTile){
    // Minus A from the current Row entered gives you an int that is useable
    int row = rowTile - 'A';
    //std::cout << "this is the rowTile in expand: " << rowTile << std::endl;
    // Expands the Row of the board
    if(row == (this->boardRow -1))this->boardRow++;

    // Expands the Col of the board
    if(colTile == (this->boardCol -1))this->boardCol++;
}


bool Board::validMove(shared_ptr<Tile> tile){
    bool validMove = false;

    // check sideways
    Col tileCol = tile->col;
    Row tileRow = tile->row;

    bool validRight = false;
    bool validLeft = false;
    bool validUp = false;
    bool validDown = false;

    int colourMatch = 1;
    int shapeMatch = 1;
  
    while(exist(tileRow, tileCol+1)){
        tileCol++;
        string tileAtPos = tilePosition(tileRow, tileCol);

        if(tile->colour != tileAtPos[0]){
            colourMatch = -1;
        }
        if(std::to_string(tile->shape) != std::string(1, tileAtPos[1])){
            shapeMatch = -1;
        } 
        if (tile->colour == tileAtPos[0] && std::to_string(tile->shape) == std::string(1, tileAtPos[1])) {
            colourMatch = -1;
            shapeMatch = -1;
        }
    }
    

    if(colourMatch != -1 || shapeMatch != -1) {
        validRight = true;
    }
    
    tileCol = tile->col;
    tileRow = tile->row;
    colourMatch = 1;
    shapeMatch = 1;

    while(exist(tileRow, tileCol-1)){
        tileCol--;
        
        string tileAtPos = tilePosition(tileRow, tileCol);
        
        if(tile->colour != tileAtPos[0]){
            colourMatch = -1;
        }
        if(std::to_string(tile->shape) != std::string(1, tileAtPos[1])){
            shapeMatch = -1;
        } 
        if (tile->colour == tileAtPos[0] && std::to_string(tile->shape) == std::string(1, tileAtPos[1])) {
            colourMatch = -1;
            shapeMatch = -1;
        }
    }

    if(colourMatch != -1 || shapeMatch != -1) {
        validLeft = true;
    }


    tileCol = tile->col;
    tileRow = tile->row;
    colourMatch = 1;
    shapeMatch = 1;

    while(exist(tileRow + 1, tileCol)){
        tileRow++;
        
        string tileAtPos = tilePosition(tileRow, tileCol);
        
        if(tile->colour != tileAtPos[0]){
            colourMatch = -1;
        }
        if(std::to_string(tile->shape) != std::string(1, tileAtPos[1])){
            shapeMatch = -1;
        } 
        if (tile->colour == tileAtPos[0] && std::to_string(tile->shape) == std::string(1, tileAtPos[1])) {
            colourMatch = -1;
            shapeMatch = -1;
        }
    }

    if(colourMatch != -1 || shapeMatch != -1) {
        validDown = true;
    }


    tileCol = tile->col;
    tileRow = tile->row;
    colourMatch = 1;
    shapeMatch = 1;

    while(exist(tileRow - 1, tileCol)){
        tileRow--;
    
        string tileAtPos = tilePosition(tileRow, tileCol);
        
        if(tile->colour != tileAtPos[0]){
            colourMatch = -1;
        }
        if(std::to_string(tile->shape) != std::string(1, tileAtPos[1])){
            shapeMatch = -1;
        } 
        if (tile->colour == tileAtPos[0] && std::to_string(tile->shape) == std::string(1, tileAtPos[1])) {
            colourMatch = -1;
            shapeMatch = -1;
        }
    }

    if(colourMatch != -1 || shapeMatch != -1) {
        validUp = true;
    }

    tileCol = tile->col;
    tileRow = tile->row;

    if (!exist(tileRow - 1, tileCol) && !exist(tileRow + 1, tileCol) && !exist(tileRow, tileCol - 1) && !exist(tileRow, tileCol + 1)){
        validMove = false;
    }
    else if (validLeft && validRight && validUp && validDown) {
        validMove = true;
    }
    else {
        std::cout << "This is not a valid move" << std::endl;
    }

    return validMove;
}

bool Board::exist(Row tileRow, Col tileCol){
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


string Board::printBoardSave(){
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

int Board::calculatePoints(Row tileRow, Col tileCol){
    int score = 0;
    int tempScore = 0;
    int leftScore = 0;
    int rightScore = 0;
    int upScore = 0;
    int downScore = 0;
    for(uint32_t k = 0; k < this->board.size(); k++){
        Row row = this->board.at(k)->row;
        Col col = this->board.at(k)->col;
        int tempRow = row;
        int tempCol = col;
        if(tileCol == col && tileRow == row){
            if(k==0){
                score++;
            }
            // check right
            if(exist(row, col+1)){
                tempScore++;
                while(exist(row, col+1)){ 
                    col++;
                    tempScore++;
                    rightScore += tempScore;
                    score += checkQwirkle(rightScore) + tempScore;
                    tempScore = 0;
                    if(exist(row, col+1) == false){
                        col = tempCol;
                        break;
                    }
                }
            }
            // check left
            if(exist(row, col-1)){
                tempScore++;
                while(exist(row, col-1)){ 
                    col--;
                    tempScore++;
                    leftScore += tempScore;
                    score += checkQwirkle(leftScore) + tempScore;
                    tempScore = 0;
                    if(exist(row, col-1) == false){
                        col = tempCol;
                        tempScore = 0;
                        break;
                    }
                }
            }
            // check up
            if(exist(row+1, col)){
                tempScore++;
                while(exist(row+1, col)){ 
                    row++;
                    tempScore++;
                    upScore += tempScore;
                    score += checkQwirkle(upScore) + tempScore;
                    tempScore = 0;
                    
                    if(exist(row+1, col) == false){
                        row = tempRow;
                        break;
                    }
                }
                
            }
            // check down
            if(exist(row-1, col)){
                tempScore++;
                while(exist(row-1, col)){ 
                    row--;
                    tempScore++;
                    downScore += tempScore;
                    score += checkQwirkle(downScore) + tempScore;
                    tempScore = 0;
                    if(exist(row-1, col) == false){
                        row = tempRow;
                        break;
                    }
                }
            }
            if(exist(row, col-1) && exist(row, col+1))
                score--;
            if(exist(row-1, col) && exist(row+1, col))
                score--;
        }
    }
    
    return score;
}

int Board::checkQwirkle(int score){
    if(score==6){
        std::cout << "Qwirkle!!!" << std::endl;
        return score;
    } else {
        return 0;
    }
}