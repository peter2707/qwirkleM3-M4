#include "Menu.h"

#define NEWGAME 1
#define LOADGAME 2
#define SHOWCREDIT 3
#define QUIT 4

Engine* e = new Engine();

Menu::Menu(){}

Menu::~Menu() {}


void Menu::mainMenu() {
    int menuOption;
    std::cout   << "--------Menu--------\n"
                << "1. New Game\n"
                << "2. Load Game\n"
                << "3. Show Credits\n"
                << "4. Quit\n> ";
    std::cin >> menuOption;
    if (std::cin.fail()) {
        std::cin.clear(); 
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Please enter a number..."<<std::endl;
        mainMenu();
    }else{
        if (menuOption == NEWGAME) {
        newGame();
        } else if (menuOption == LOADGAME) {
            loadGame();
        } else if (menuOption == SHOWCREDIT) {
            showCredits();
        } else if (menuOption == QUIT) {
            quit();
        } else {
            std::cout<<"Sorry, invalid option..."<<std::endl;
            mainMenu();
        }
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
        if (playerTwoName == playerOneName){
            std::cout<<"Sorry, this name is already chosen"<<std::endl;
            mainMenu();
        }else{
            if (checkPlayerName(playerTwoName) == true){
                std::cout<<"Let's Play..."<<std::endl;
                //Game Play
            }else{
                std::cout<<"Sorry, Invalid Player Two's name"<<std::endl;
                mainMenu();
            }
        }
    }else{
        std::cout<<"Sorry, Invalid Player One's name"<<std::endl;
        mainMenu();
    }
}

void Menu::loadGame() {
    std::string filename;
    bool validFile = false;

    while(!validFile){
     std::cout << "Enter a file name to load from\n >";
     std::cin >> filename;
     std::ifstream in;
     in.open("save_game/" +filename);

     if(in.fail()){
       std::cout << "Please enter a correct file name" << std::endl;
     } else{
       validFile = true;
     }
     in.close();
  }
    e->loadGame(filename);
}


void Menu::showCredits() {
    std::cout<<"------------------------------------\n"
             <<"-------------Team-MAST--------------\n"
             <<"------------------------------------\n"
             <<"Name: Monkolsophearith Prum\n"
             <<"Student ID: s3848409\n"
             <<"Email: s3848409@student.rmit.edu.au\n" 
             <<"------------------------------------\n" 
             <<"Name: Anmol Kumar\n"
             <<"Student ID: s3545259\n" 
             <<"Email: s3545259@student.rmit.edu.au\n" 
             <<"------------------------------------\n" 
             <<"Name: Sokleng Lim\n"
             <<"Student ID: s3813756\n" 
             <<"Email: s3813756@student.rmit.edu.au\n" 
             <<"------------------------------------\n" 
             <<"Name: Tony Peter Baker\n" 
             <<"Student ID: s3622250\n" 
             <<"Email: s3622250@student.rmit.edu.au\n" 
             <<"------------------------------------\n"<<std::endl;
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
