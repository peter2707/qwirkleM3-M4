#include "Menu.h"

Menu::~Menu() {
    
}


void Menu::mainMenu() {
   int menuOption;
   std::cout << "--------Menu--------" << std::endl;
   std::cout << "1. New Game" << std::endl;
   std::cout << "2. Load Game" << std::endl;
   std::cout << "3. Show Credits" << std::endl;
   std::cout << "4. Quit" << std::endl << "> ";
   std::cin >> menuOption;
   std::cout << std::endl;
   if (menuOption == 1) {
      newGame();
   } else if (menuOption == 2) {
      loadGame();
   } else if (menuOption == 3) {
      showCredits();
   } else if (menuOption == 4) {
      quit();
   } else {
      std::cout<<"Sorry, invalid option..."<<std::endl;
   }
}

void Menu::newGame() {
    std::string playerOneName = "";
    std::string playerTwoName = "";

    std::cout << "Starting a new game...\n" << std::endl;
    std::cout << "Enter a name for Player 1 (Uppercase characters only!)" << std::endl;
    std::cin >> playerOneName;
    if (checkPlayerName(playerOneName) == true){
        std::cout<<"Enter a name for Player 2 (Uppercase characters only!)"<<std::endl;
        std::cin >> playerTwoName;
        if (checkPlayerName(playerTwoName) == true){
            std::cout<<"Let's Play..."<<std::endl;
            //Game Play
        }else{
            std::cout<<"Sorry, Invalid Player Two's name"<<std::endl;
        }
    }else{
        std::cout<<"Sorry, Invalid Player One's name"<<std::endl;
    }
}

void Menu::loadGame() {
    std::string filename;
    std::cout << "Enter the filename to load a game" << std::endl << "> ";
    std::cin >> filename;
}


void Menu::showCredits() {
    std::cout<<"------------------------------"<<std::endl;
    std::cout<<"----------Team-MAST-----------"<<std::endl;
    std::cout<<"------------------------------"<<std::endl;
    std::cout<<"Name: Monkolsophearith Prum"<<std::endl;
    std::cout<<"Student ID: s3848409"<<std::endl;
    std::cout<<"Email: s3848409@student.rmit.edu.au"<<std::endl;
    std::cout<<"------------------------------"<<std::endl;
    std::cout<<"Name: Anmol Kumar"<<std::endl;
    std::cout<<"Student ID: s3545259"<<std::endl;
    std::cout<<"Email: s3545259@student.rmit.edu.au"<<std::endl;
    std::cout<<"------------------------------"<<std::endl;
    std::cout<<"Name: Sokleng Lim"<<std::endl;
    std::cout<<"Student ID: s3813756"<<std::endl;
    std::cout<<"Email: s3813756@student.rmit.edu.au"<<std::endl;
    std::cout<<"------------------------------"<<std::endl;
    std::cout<<"Name: Tony Peter Baker"<<std::endl;
    std::cout<<"Student ID: s3622250"<<std::endl;
    std::cout<<"Email: s3622250@student.rmit.edu.au"<<std::endl;
    std::cout<<"------------------------------\n"<<std::endl;
    mainMenu();
}

void Menu::quit(){
  std::cout << "Goodbye!" <<std::endl;
  exit(0);
}

bool Menu::checkPlayerName(std::string name){
    bool check = false;
    if (!name.empty()){
        uint64_t count = 0;
        for(uint64_t i = 0; i < name.length(); i++){
            if(isupper(name[i]) == true){
                ++count;
            }
        }
        if (count == name.length()){
            check = true;
        }else {
            check = false;
        }
    }else {
        check = false;
    }
    return check;
}
