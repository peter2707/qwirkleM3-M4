
#include "LinkedList.h"
#include "Menu.h"
#include <iostream>
#include "Engine.cpp"


#define EXIT_SUCCESS 0

int main(void) {
   std::cout << "Welcome To Qwirkle!" << std::endl;

   LinkedList* list = new LinkedList();
   delete list;
   Engine* engine = new Engine();
   engine->loadGame("save_game/save");
   // Menu* menu = new Menu();
   // menu->mainMenu();
   // delete menu;
}
