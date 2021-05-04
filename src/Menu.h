#ifndef ASSIGN2_MENU_H
#define ASSIGN2_MENU_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "Engine.h"

class Menu {

public:

    Menu();
    /* Deconstructor */
    ~Menu();

    /* Game Menu */
    void mainMenu();
    void newGame();
    void loadGame();
    void showCredits();
    void quit();

    /* Functions */
    bool checkPlayerName(std::string name);

private:

};
#endif // ASSIGN2_MENU_H