#include "Engine.h"

Engine::Engine(){
    this->board = new Board();
}

Engine::~Engine(){

}

void Engine::startGame(Player* playerList[], int numPlayer)
{
    this->players[0] = playerList[0];
    this->players[1] = playerList[1];
    shuffleBag();
    giveTiles();
}

void Engine::giveTiles()
{

}

void Engine::shuffleBag()
{
    std::random_device engine;
    std::map<int, char> colorMap = {{0, RED}, {1, ORANGE}, {2, YELLOW}, {3, GREEN}, {4, BLUE}, {5, PURPLE}};
    std::map<int, int> shapeMap = {{0, CIRCLE}, {1, STAR_4}, {2, DIAMOND}, {3, SQUARE}, {4, STAR_6}, {5, CLOVER}};
    for (unsigned int x = 0; x < colorMap.size(); x++){
        for (unsigned int y = 0; y < shapeMap.size(); y++){
            for (unsigned int z = 0; z < NUM_OF_EACH_TILE; z++){
                // bag.addBack(new Tile(colourMap[x], shapeMap[y]));
            }
        }
    }
    int index = 0;
    for (int i = 0; i < MAX_NUM_OF_TILE; i++)
    {
        std::uniform_int_distribution<int> uniform_dist(0, MAX_NUM_OF_TILE - 1 - i);
        index = uniform_dist(engine);
        // bag.addBack(new Tile(*(bag.getTileAt(index))));
        // bag.deleteAt(index);
    }
}

void Engine::gameRun()
{
    // Future will be until bag is empty or someone types in close or exit
    while(true)
    {
        for(int i = 0; i < PLAYERS; i++)
        {
            bool endturn = false;
            while(!endturn)
            {
                // // Prints the board
                this->board->printBoard();
                
                
                // Sets the current player name so when we save it will store the current player
                this->currentPlayer = players[i]->getName();
                
                // Prints out the current player and their hand
                std::cout << "Player " << this->currentPlayer << " Place tile on the board" << std::endl;
                std::cout << players[i]->getHand() << std::endl;

                //Waits for player to input their option
                string option;
                std::cout << "> ";
                std::getline(std::cin, option);
                
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
                        endturn = placeTile(/*players[i],*/ tile, row, col);
                    }
                }
                // Quits game when user types quit. Needs to be implimented
                if(std::regex_match(option, std::regex("^(quit|exit)$")))
                {
                    
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
    }
}

bool Engine::placeTile(/*Player* curPlayer,*/ string tilePlaced, Row row, Col col)
{
    bool success = false;
    // Check if tile is in player bag
    // TO BE DONE

    // Create shared_ptr for placing tile on board

    std::cout << tilePlaced << "\n";
    shared_ptr<Tile> tilePtr(new Tile(tilePlaced[0], (tilePlaced[1] - '0')));
    tilePtr->row = row;
    tilePtr->col = col;

    // place on board
    success = board->placeTile(tilePtr);

    // If tile failed to place
    
    if(!success)
    {
        std::cout << "Failed to place tile " << tilePlaced << " at " << row << col << "\n";
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
        write << this->players[i]->getHand() << std::endl;
    }

    // save board size
    write << board->getLength() << std::endl;
    // save board state
    write << board->printBoardSave() << std::endl;
    // save tiles in bag
    write << bag << std::endl;

    // save currentPlayer turn
    write << this->currentPlayer << std::endl;

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

