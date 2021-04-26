
#include "LinkedList.h"
#include "Menu.h"
#include <iostream>

#define EXIT_SUCCESS 0

int main(void) {
   std::cout << "Welcome To Qwirkle!" << std::endl;

   LinkedList* list = new LinkedList();
   delete list;

   Menu* menu = new Menu();
   menu->mainMenu();
   delete menu;
}
