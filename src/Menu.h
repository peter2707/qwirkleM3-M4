#ifndef MENU_H
#define MENU_H
#include <iostream>

class Menu {

public:

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
#endif // MENU_H