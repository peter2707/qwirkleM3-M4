
#include <iostream>
#include "Menu.h"

#define EXIT_SUCCESS 0

int main(void) {
   std::cout << "Welcome To Qwirkle!" << std::endl;
   LinkedList* playerhand = new LinkedList();
   
   delete playerhand;

   Menu* menu = new Menu();
   menu->mainMenu();
   delete menu;

   return EXIT_SUCCESS;
}
