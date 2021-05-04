#ifndef ASSIGN2_MENU_H
#define ASSIGN2_MENU_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "Engine.h"

class Menu {

public:
    /* constructor */
    Menu();

    /* Deconstructor */
    ~Menu();

    /* Game Menu */
    void mainMenu();

private:
    /* Menu functions */
    void newGame();
    void loadGame();
    void showCredits();
    void quit();

    /* Functions */
    bool checkPlayerName(std::string name);

};
#endif // ASSIGN2_MENU_H