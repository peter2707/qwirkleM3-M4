
#include "LinkedList.h"
#include <iostream>

#define EXIT_SUCCESS 0

//Functions
void menu();
void newGame();
void loadGame();
void showCredits();
void quit();

int main(void) {
   LinkedList* list = new LinkedList();
   delete list;

   std::cout << "Welcome To Qwirkle!" << std::endl;
   menu();
}

void menu() {
   int command;
   std::cout << "--------Menu--------" << std::endl;
   std::cout << "1. New Game" << std::endl;
   std::cout << "2. Load Game" << std::endl;
   std::cout << "3. Show Credits" << std::endl;
   std::cout << "4. Quit" << std::endl;
   std::cout << "> ";
   std::cin >> command;
   std::cout << std::endl;
   if (command == 1) {
      //new game
   } else if (command == 2) {
      //load game
   } else if (command == 3) {
      showCredits();
   } else if (command == 4) {
      quit();
   } else {
      std::cout<<"Sorry, invalid option..."<<std::endl;
   }
}

void newGame() {

}

void loadGame() {

}

void showCredits() {
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
   menu();
}

void quit(){
  std::cout << "Goodbye!" << '\n';
  exit(0);
}