#include "Engine.h"

Engine::Engine(){

}

Engine::~Engine(){

}

void Engine::startGame(Player playerList[], int numPlayer)
{
    // this->players[0] = playerList[0];
    // this->players[1] = playerList[1];
}

void Engine::shuffleBag()
{

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

