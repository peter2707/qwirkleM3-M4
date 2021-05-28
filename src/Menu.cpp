#include "Menu.h"

Menu::Menu(){}

Menu::~Menu() {}

void Menu::mainMenu() {
    int menuOption;
    bool showMenu = true;
    //print menu
    std::cout   << "--------Menu--------\n"
                << "1. New Game\n"
                << "2. Load Game\n"
                << "3. Show Credits\n"
                << "4. Help\n"
                << "5. Quit\n> ";
    do {
        while(showMenu){
            //get user input
            std::cin >> menuOption;
            //check if user input ctrl+d
            if (std::cin.eof()) {
                quit();
            }else {
                //if user input anything else than number, this will run
                while (std::cin.fail()) {
                    std::cin.clear(); 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Please enter a number...\n> ";
                    showMenu = true;
                }
                if (menuOption == NEWGAME) {
                    newGame();
                    showMenu = false;
                } else if (menuOption == LOADGAME) {
                    loadGame();
                    showMenu = false;
                } else if (menuOption == SHOWCREDIT) {
                    showCredits();
                    std::cout << "> ";
                    showMenu = true;
                } else if (menuOption == HELP) {
                    e->help();
                    std::cout << "> ";
                    showMenu = true;
                } else if (menuOption == QUIT) {
                    quit();
                } else {
                    std::cout<<"Sorry, invalid option...\n> ";
                    showMenu = true;
                }
            }
        }
    }while(menuOption != NEWGAME || menuOption != LOADGAME || menuOption != SHOWCREDIT || menuOption != QUIT);
}

void Menu::newGame() {
    bool success = false;
    std::cout << "Starting a new game...\n" << std::endl;
    std::cout << "Enter amount of players (2-4)\n> ";
    while (!success) {
        std::cin >> playerAmount;
        if (std::cin.eof()) {
            quit();
        }else if(std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a number...\n> ";
            success = false;
        }else if(playerAmount < 2 || playerAmount > 4) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Player amount must be between 2 and 4\n> ";
            success = false;
        }else {
            Player *players[playerAmount];
            for(int i=0; i < playerAmount; i++){
                bool check = false;
                std::cout << "Enter a name for Player "<< i + 1 <<" (Uppercase characters only!)\n> ";
                while(check!=true){
                    std::cin >> playerName;
                    if (std::cin.eof()) {
                        quit();
                    }else{
                        //check if player name is valid
                        if(checkPlayerName(playerName) != true){
                            std::cout<<"Sorry, Invalid Player's name\n> ";
                            check = false;
                        }else{
                            players[i] = new Player(playerName);
                            if(i == 1){
                               if(players[i]->getName() == players[i-1]->getName()){
                                   std::cout<<"Sorry, this name is already taken...\n> ";
                                   check = false;
                                }else
                                    check = true;
                            }else if(i == 2){
                                if(players[i]->getName() == players[i-1]->getName()||
                                   players[i]->getName() == players[i-2]->getName()){
                                   std::cout<<"Sorry, this name is already taken...\n> ";
                                   check = false;
                                }else
                                    check = true;
                            }else if(i == 3){
                                if(players[i]->getName() == players[i-1]->getName()||
                                   players[i]->getName() == players[i-2]->getName()||
                                   players[i]->getName() == players[i-3]->getName()){
                                   std::cout<<"Sorry, this name is already taken...\n> ";
                                   check = false;
                                }else
                                    check = true;
                            }else {
                                check = true;
                            }
                        }
                        
                    }
                }
            }
            e->startGame(players, playerAmount);
            delete e;
            quit();
        }
    }
}

void Menu::loadGame() {
    std::string filename;
    bool validFile = false;
    //get file name via std::cin
    while(!validFile){
        std::ifstream in;
        std::cout << "Enter a file name to load from\n> ";
        std::cin >> filename;
        if (std::cin.eof()) {
            quit();
        }else{
            //open file from save_game folder
            in.open("save_game/" + filename);
            if(in.fail()){
                std::cout << "Please enter a correct file name..." << std::endl;
            } else{
                validFile = true;
            }
            in.close();
        }
    }
    e->loadGame(filename);
    quit();
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
             <<"------------------------------------\n"
             <<std::endl;
}

void Menu::quit(){
  std::cout << "Goodbye!" <<std::endl;
  exit(0);
}

//check player name function
bool Menu::checkPlayerName(std::string name){
    bool check = false;
    //check if name is not empty and if it's all capital characters by counting the length of capital characters
    //in the name and compare it with the name's length
    if (!name.empty()){
        uint64_t count = 0;
        for(uint64_t i = 0; i < name.length(); i++){
            if(isCapital(name[i]) == true){
                ++count;
            }
        }
        if (count == name.length()){
            check = true;
        }
    }
    return check;
}

//check if a character is capital
bool Menu::isCapital(char x){
    bool cap = false;
    if (x >='A' && x <= 'Z'){
        cap = true;
    }
    return cap;
}
