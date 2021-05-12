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
    std::map<int, char> colorMap = {{0, RED}, {1, ORANGE}, {2, YELLOW}, {3, GREEN}};
    std::map<int, int> shapeMap = {{0, CIRCLE}, {1, STAR_4}, {2, DIAMOND}, {3, SQUARE}};

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
    bool exit = false;
    // Future will be until bag is empty or someone types in close or exit
    int playerNo = 0;
    do
    {
        
        bool endturn = false;
        do 
        {
            if(!exit)
            {
                std::cin.ignore();
                // Sets the current player name so when we save it will store the current player
                this->currentPlayer = players[playerNo];
                std::cout << this->currentPlayer->getName() << ", it's your turn" << std::endl;
                std::cout << "Score for " << this->players[0]->getName() + ": "<< this->players[0]->getScore() << std::endl;
                std::cout <<  "Score for " << this->players[1]->getName() + ": " << this->players[1]->getScore() << std::endl;
                // Prints the board
                this->board->printBoard();
                std::cout << "\n" << std::endl;               
                
                // Prints out the current player and their hand
                std::cout << "Your hand is" << std::endl;
                std::cout << this->currentPlayer->getHandString() << std::endl;

                //Waits for player to input their option
                string option;
                std::cout << "> ";
                // Detects if ctrl + d is pressed
                if(std::getline(std::cin, option))
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
                // If it is pressed will set endturn and exit
                else
                {
                    exit = true;
                    endturn = true;
                }
            }
        } while(!endturn);
        
        if(playerNo == (PLAYERS - 1))playerNo = 0;
        else playerNo++;

    } while(!endGame(currentPlayer) || !exit);
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
    if(!(col > this->board->boardCol) && !(rowCheck > this->board->boardRow))
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
        Player* player1 = new Player();
        //Player* player2 = new Player();
        
        int lineCount = 0;
        while(std::getline(file, line))
        {
            if(lineCount == PLAYER1)
            {
                player1->playerName = line;
            }
            if(lineCount == PLAYER1_SCORE)
            {
                std::stringstream stringScore(line);
                stringScore >> player1->score;
            }
            if(lineCount == PLAYER1_HAND)
            {
                std::cout << "PLAYER 1 Hand" << std::endl;
                std::cout << line << std::endl;
            }
            if(lineCount == PLAYER2)
            {
                std::cout << "PLAYER 2" << std::endl;
                std::cout << line << std::endl;
            }
            if(lineCount == PLAYER2_SCORE)
            {
                std::cout << "PLAYER 2 Score" << std::endl;
                std::cout << line << std::endl;
            }
            if(lineCount == PLAYER2_HAND)
            {
                std::cout << "PLAYER 2 Hand" << std::endl;
                std::cout << line << std::endl;
            }
            if(lineCount == BOARD)
            {
                std::cout << "BOARD" << std::endl;
                std::cout << line << std::endl;
            }
            if(lineCount == BAG)
            {
                std::cout << "BAG" << std::endl;
                std::cout << line << std::endl;
            }
            if(lineCount == CURRENT_PLAYER)
            {
                std::cout << "CURRENT PLAYER" << std::endl;
                std::cout << line << std::endl;
            }
            lineCount++;
        }
    }
    else
    {
        std::cout << "Failed to load " << fileName << std::endl;
    }
}
