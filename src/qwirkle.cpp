
#include <iostream>
#include "Menu.h"
#include "Board.h"
#include "TileCodes.h"
#include <regex>
#include <string>
#include "Engine.h"

#define EXIT_SUCCESS 0

int main(void) {
   std::cout << "Welcome To Qwirkle!" << std::endl;

   Engine* engine = new Engine();
   engine->gameRun();

   // Board* board = new Board();
   // std::string option;
   // std::getline(std::cin, option);
   // std::cout << std::regex_match(option, std::regex("^(place) ([R|O|Y|G|B|P][1-6]) (at) ([A-Z][0-25])$")) << "\n";
   // if(std::regex_match(option, std::regex("^(place) ([R|O|Y|G|B|P][1-6]) (at) ([A-Z][0-25])$")))
   // {
   //    std::smatch match;
   //    if(std::regex_search(option, match, std::regex("^(place) ([R|O|Y|G|B|P][1-6]) (at) ([A-Z][0-25])$")))
   //    {
   //       string tileCode = match.str(REGEX_TILE); 
   //       string location = match.str(REGEX_POSI);
         
         
         
   //       Tile* tile = new Tile(tileCode[0], (int)tileCode[1]);
   //       tile->col = (int)location[1];
   //       tile->row = location[0];

   //       std::cout << board->placeTile(shared_ptr<Tile>(tile), nullptr) << "\n";
   //       board->printBoard();
   //    }
   // }
   
   

   //board->addTile(shared_ptr<Tile>(tile));
   
   // Menu* menu = new Menu();
   // menu->mainMenu();
   // delete menu;

   return EXIT_SUCCESS;
}
