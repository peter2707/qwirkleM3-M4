#include "Engine.h"

Engine::Engine(){

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

}

void Engine::gameRun()
{
    // Future will be until bag is empty or someone types in close or exit
    while(true)
    {
        for(int i = 0; i < PLAYERS; i++)
        {
            // Prints the board
            this->board->printBoard();
            string option;
            
            // Sets the current player name so when we save it will store the current player
            this->currentPlayer = players[i]->getName();
            
            // Prints out the current player and their hand
            std::cout << "Player " << this->currentPlayer << " Place tile on the board" << std::endl;
            std::cout << players[i]->getHand() << std::endl;

            //Waits for player to input their option
            std::cout << "> ";
            std::getline(std::cin, option);
            
            // Regex isn't fun, but it helps with checking user input and splitting the option
            if(std::regex_match(option, std::regex("^(place) ([R|O|Y|G|B|P][1-6]) (at) ([A-Z][0-25])$")))
            {
                std::smatch match;
                if(std::regex_search(option, match, std::regex("^(place) ([R|O|Y|G|B|P][1-6]) (at) ([A-Z][0-25])$")))
                {
                    string tile = match.str(REGEX_TILE); 
                    string location = match.str(REGEX_POSI);
                    placeTile(players[i], tile, location);
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

void Engine::placeTile(Player* curPlayer, string tilePlaced, string location)
{

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

