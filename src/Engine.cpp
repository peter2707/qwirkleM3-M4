#include "Engine.h"

Engine::Engine(){

}

Engine::~Engine(){

}

void Engine::startGame(Player playerList[], int numPlayer)
{
    this->players[0] = playerList[0];
    this->players[1] = playerList[1];
}

void Engine::shuffleBag()
{
    
}

// void Engine::loadGame(Board bord, Player playerList[])
// {
    
// }

void Engine::loadGame(std::string filename){
    std::cout<< "Hi"<<filename<<std::endl;
}

