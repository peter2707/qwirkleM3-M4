#include "Engine.h"

Engine::Engine(){
    this->board = new Board();
}

Engine::~Engine(){

}

void Engine::startGame(Player* playerList[], int numPlayer)
{
    bag = std::make_shared<LinkedList>();
    this->players[0] = playerList[0];
    this->players[1] = playerList[1];
    initialiseBag();
    randomiseBag();
    giveTiles();
    gameRun();
}

void Engine::giveTiles()
{
    // Loop to give tiles to all players
    for(int i = 0; i < PLAYERS; i++){
        shared_ptr<LinkedList> giveTiles = std::make_shared<LinkedList>();
        for(int i=0; i < START_SIZE; i++){
            shared_ptr<Tile> t = bag->removeFront();
            giveTiles->addBack(t);
        }
        players[i]->setPlayerHand(giveTiles);
    }
}

void Engine::initialiseBag()
{
    std::map<int, char> colorMap = {{0, RED}, {1, ORANGE}, {2, YELLOW}, {3, GREEN}, {4, BLUE}, {5, PURPLE}};
    std::map<int, int> shapeMap = {{0, CIRCLE}, {1, STAR_4}, {2, DIAMOND}, {3, SQUARE}, {4, STAR_6}, {5, CLOVER}};

    for (unsigned int x = 0; x < colorMap.size(); x++){
        for (unsigned int y = 0; y < shapeMap.size(); y++){
            for (unsigned int z = 0; z < NUM_OF_EACH_TILE; z++){
                std::shared_ptr<Tile> tile = std::make_shared<Tile>(colorMap[x], shapeMap[y]);
                bag->addBack(tile);
            }
        }
    }
}

void Engine::randomiseBag(){
    
    std::random_device engine;

    for (int i = 0; i < MAX_NUM_OF_TILE * 2; i++)
    {
        srand(time(NULL));
        int ran = rand() % MAX_NUM_OF_TILE;
        std::uniform_int_distribution<int> uniform_dist(0, ran - 1);
        ran = uniform_dist(engine);
        std::shared_ptr<Tile> tile = std::make_shared<Tile>(*bag->get(ran));
        bag->addBack(tile);
        bag->removeIndex(ran);
    }

}



void Engine::gameRun()
{
    std::cout << "GameRun 1\n";
    bool exit = false;
    int playerNo = 0;

    // This is for loading the game, will check the current player and gets the playerno
    // of the current player
    if(this->currentPlayer != nullptr)
    {
        for(int i = 0; i < PLAYERS; i++) if(players[i]->getName() == currentPlayer->getName()) playerNo = i;
    }
    std::cout << "GameRun 2\n";
    do
    {
        bool endturn = false;
        if(currentPlayer == nullptr)
            // Provents double print of the board, Do not delete please
            std::cin.ignore();
                
        // Sets the current player name so when we save it will store the current player
        this->currentPlayer = players[playerNo];
        std::cout << "\n" << std::endl;
        std::cout << this->currentPlayer->getName() << ", it's your turn" << std::endl;
        std::cout << "Score for " << this->players[0]->getName() + ": "<< this->players[0]->getScore() << std::endl;
        std::cout <<  "Score for " << this->players[1]->getName() + ": " << this->players[1]->getScore() << std::endl;
        // Prints the board
        this->board->printBoard();
        std::cout << "\n" << std::endl;               
        
        // Prints out the current player and their hand
        std::cout << "Your hand is" << std::endl;
        std::cout << this->currentPlayer->getHandString() << std::endl;
        std::cout << "\n" << std::endl;

        do 
        {
            // Checks if exit is set
            if(!exit)
            {
                
                //Waits for player to input their option
                string option;
                std::cout << "> ";
                // Detects if ctrl + d is pressed
                std::getline(std::cin, option);
                if(std::cin.eof())
                {
                    exit = true;
                    endturn = true;
                }
                else
                {
                    // Regex isn't fun, but it helps with checking user input and splitting the option
                    if(std::regex_match(option, std::regex("^(place) ([R|O|Y|G|B|P][1-6]) (at) ([A-Z])([0-9]|1[0-9]|2[0-5])$")))
                    {
                        std::smatch match;
                        if(std::regex_search(option, match, std::regex("^(place) ([R|O|Y|G|B|P][1-6]) (at) ([A-Z])([0-9]|1[0-9]|2[0-5])$")))
                        {
                            
                            string tile = match.str(REGEX_TILE); 
                            Row row = match.str(REGEX_ROW)[0];
                            std::stringstream temp(match.str(REGEX_COL));
                            Col col;
                            temp >> col;
                            endturn = placeTile(this->currentPlayer, tile, row, col);
                        }
                    }
                    
                    if(std::regex_match(option, std::regex("^(replace) ([R|O|Y|G|B|P][1-6])$"))){
                        std::smatch match;
                        if(std::regex_search(option, match, std::regex("^(replace) ([R|O|Y|G|B|P][1-6])$")))
                        {                       
                            string tile = match.str(REGEX_TILE); 
                            endturn = replaceTile(this->currentPlayer, tile);
                        }

                    }
                    else{
                        std::cout << "Invalid move, please try again" << std::endl;

                    }

                    // Quits game when user types quit. Needs to be implimented
                    if(std::regex_match(option, std::regex("^(quit|exit)$")))
                    {
                        exit = true;
                        endturn = true;
                    }
                    // Saves the game based on the save file user puts in
                    if(std::regex_match(option, std::regex("^(save) ([a-z0-9]+)$")))
                    {
                        std::smatch match;
                        if(std::regex_search(option, match, std::regex("^(save) ([a-z0-9]+)$")))
                        {
                            string filename = match.str(REGEX_SAVE);
                            saveGame(filename);
                        }
                    }
                }
            }
        } while(!endturn);  
        
        if(playerNo == (PLAYERS - 1))playerNo = 0;
        else playerNo++;

    } while(!endGame(currentPlayer) && !exit);
}

bool Engine::replaceTile(Player* curPlayer, std::string tilePlaced){
    bool success = false;
    int index = curPlayer->getHand()->checkTile(tilePlaced);

    if (index != -1){
        bag->addBack(curPlayer->getHand()->get(index));
        curPlayer->getHand()->removeIndex(index);
        curPlayer->getHand()->addBack(bag->removeFront());
        success = true;
        std::cout << "Tile successfully replaced" << std::endl;
    }
    else{
        std::cout << "You do not have that tile" << std::endl;
    }
    return success;
}

bool Engine::placeTile(Player* curPlayer, std::string tilePlaced, Row row, Col col)
{
    bool success = false;
    // Check if tile is in player bag
    int index = curPlayer->getHand()->checkTile(tilePlaced);
    int rowCheck = (row - 'A');
    // Checks if coordinates entered is not greater than the current board size
    if(!(col >= this->board->boardCol) && !(rowCheck >= this->board->boardRow))
    {
        if (index != -1)
        {
            // Gets tile from players bag
            shared_ptr<Tile> tilePtr = curPlayer->getHand()->get(index);
            // Sets the tile col and row
            tilePtr->row = row;
            tilePtr->col = col;
            // Places it on the board
            success = board->placeTile(tilePtr);

            if(success)
            {
                // Removes tile from players hand
                curPlayer->getHand()->removeIndex(index);

                // Adds tile to the player bag
                if(bag->size() > 0){
                curPlayer->getHand()->addBack(bag->removeFront());
                }
                // Calculate Score
                // this should only be called when the a tile is successfully placed.
                int score = board->calculatePoints(row, col);
                curPlayer->addScore(curPlayer->getScore() + score);
            }
        }
        else{
            std::cout << "You do not have that tile" << std::endl;
        }
    }
    else
    {
        std::cout << "Coordinates entered is out of the board size\n";
    }
    // If tile failed to place
    
    if(!success)
    {
        std::cout << "Failed to place tile " << tilePlaced << " at " << row << col << "\n";
    }
    return success;
}

bool Engine::endGame(Player* curPlayer){
    bool success = false;
    // Checks if the bag size and the player bag is empty
    if(bag->size() == 0 && curPlayer->getHand()->size() == 0){
        success = true;
        std::cout << "Game Over" <<std::endl;
        std::cout << "Score for " << this->players[0]->getName() << ": " <<this->players[0]->getScore() << std::endl;
        std::cout << "Score for " << this->players[1]->getName() << ": "<<this->players[1]->getScore() << std::endl;
        if (this->players[0]->getScore() > this->players[1]->getScore()){
            std::cout << "Player "<< this->players[0]->getName() << " won" << std::endl;
        }
        else if (this->players[0]->getScore() < this->players[1]->getScore()){
            std::cout << "Player "<< this->players[1]->getName() << " won" << std::endl;
        }
        else{
            std::cout << "Game Tied!" << std::endl;
        }
        std::cout << "\n" <<std::endl;
        std::cout << "Goodbye!" <<std::endl;
        exit(0);
    }
    return success;
}

void Engine::saveGame(string fileName)
{
    std::ofstream write;
    write.open("save_game/"+fileName);

    // save player name, score and hand
    for(int i = 0; i < PLAYERS; i++)
    {
        write << this->players[i]->getName() << std::endl;
        write << this->players[i]->getScore() << std::endl;
        write << this->players[i]->getHandString() << std::endl;
    }

    // save board size
    write << board->boardRow << "," << board->boardCol <<std::endl;
    // save board state
    if(board->printBoardSave().empty())
        write << "[No board records.]" << std::endl;
    else 
        write << board->printBoardSave() << std::endl;
    // save tiles in bag
    for(int i = 0; i < bag->size() ; i++){
        if(i==bag->size()-1)
            write << bag->get(i)->colour << bag->get(i)->shape << std::endl ;
        else
            write << bag->get(i)->colour << bag->get(i)->shape << ",";
    }

    // save currentPlayer turn
    write << this->currentPlayer->getName();

    write.close();
}
void Engine::loadGame(string fileName)
{
    string line;
    std::ifstream file("save_game/"+fileName);

    if(file.is_open())
    {
        // Sets up Engine variables
        this->players[0] = new Player();
        this->players[1] = new Player();
        this->board = new Board();
        bag = std::make_shared<LinkedList>();
        // Helps determinee what line we are up to
        int lineCount = 0;

        // Loops through all the lines in the save file
        while(std::getline(file, line))
        {
            // Sets Player 1 Name
            if(lineCount == PLAYER1)
            {
                this->players[0]->setName(line);
            }
            // Sets Player 1 Score
            if(lineCount == PLAYER1_SCORE)
            {
                std::stringstream stringScore(line);
                stringScore >> this->players[0]->score;
            }
            // Sets Player 1 hand
            if(lineCount == PLAYER1_HAND)
            {   
                playerHand(line, this->players[0]);
            }
            // Sets Player 2 Name
            if(lineCount == PLAYER2)
            {
                this->players[1]->setName(line);
            }
            // Sets Player 2 Score
            if(lineCount == PLAYER2_SCORE)
            {
                std::stringstream stringScore(line);
                stringScore >> this->players[1]->score;
            }
            // Sets Player 2 hand
            if(lineCount == PLAYER2_HAND)
            {
                playerHand(line, this->players[1]);
            }
            // Sets Board Size
            if(lineCount == BOARD_Size)
            {
                std::vector<std::string> size;
                split(line, ',', size);
                std::stringstream col(size.at(0));
                std::stringstream wid(size.at(1));
                col >> board->boardRow;
                wid >> board->boardCol;
            }
            // Sets Board
            if(lineCount == BOARD)
            {
                // Checks if there are any pieces on the board
                if(!(line == "[No board records.]"))
                {
                    // Splits all the tiles
                    std::vector<std::string> tiles;
                    split(line, ',', tiles);

                    // Loops throught all the tiles in the Vector
                    for(unsigned int i = 0; i < tiles.size(); i++)
                    {
                        // Regex Splits the tiles up
                        std::smatch match;
                        if(std::regex_search(line, match, std::regex("^([R|O|Y|G|B|P][1-6])@([A-Z][0-9]|1[0-9]|2[0-5])$")))
                        {
                            // Create tile to be placed in the board
                            string tileCode = match.str(1);
                            string tilePos  = match.str(2);
                            std::shared_ptr<Tile> tile1 = std::make_shared<Tile>(tileCode[0], 
                                                                                (tileCode[1] - '0'), 
                                                                                tilePos[0], 
                                                                                (tilePos[1] - '0'));
                            this->board->addTile(tile1);
                        }
                    }
                }
            }
            // Sets the bag
            if(lineCount == BAG)
            {
                // Splits all the tiles
                std::vector<std::string> tiles;
                split(line, ',', tiles);

                // Loops throught all the tiles in the Vector
                for(unsigned int i = 0; i < tiles.size(); i++)
                {   
                    // Creates a tile and puts it in the tile bag
                    std::string tile = tiles.at(i);
                    Colour colour = tile[0];
                    Shape  shape = tile[1] - '0';
                    std::shared_ptr<Tile> tile1 = std::make_shared<Tile>(colour, shape);]
                    this->bag->addBack(tile1);
                }
            }
            if(lineCount == CURRENT_PLAYER)
            {
                // Checks what player is up and sets the current player
                for(int i = 0; i < PLAYERS; i++)
                {
                    if(this->players[i]->getName() == line)
                    {
                        this->currentPlayer = this->players[i];
                    }
                }
            }
            lineCount++;
        }
        gameRun();
    }
    else
    {
        std::cout << "Failed to load " << fileName << std::endl;
    }
}


// Referenced from Stackoverflow, cuts the string into a vector
// https://stackoverflow.com/questions/16749069/c-split-string-by-regex/16752826
std::vector<std::string>& Engine::split(const std::string &s, char delim,std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        if (item.length() > 0) {
            elems.push_back(item);  
        }
    }
    return elems;
}

// Set the player hand
void Engine::playerHand(string playerHand, Player* player)
{
    shared_ptr<LinkedList> hand = std::make_shared<LinkedList>();
    std::vector<std::string> tiles;
    split(playerHand, ',', tiles);
    for(unsigned int i = 0; i < tiles.size(); i++)
    {
        std::string tile = tiles.at(i);
        Colour colour = tile[0];
        Shape  shape = tile[1] - '0';
        std::shared_ptr<Tile> tile1 = std::make_shared<Tile>(colour, shape);
        hand->addBack(tile1);
    }
    player->setPlayerHand(hand);
}