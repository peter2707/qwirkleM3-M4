
#include "LinkedList.h"
#include <stdexcept>
#include <iostream>

LinkedList::LinkedList() {
   head = nullptr;
}


LinkedList::~LinkedList() {
  clear();
}

LinkedList::LinkedList(LinkedList& other){
  head = nullptr;
  for(int i = 0; i < other.size(); ++i){
      std::shared_ptr<Tile> tile = std::make_shared<Tile>(*other.get(i));
      addBack(tile);
  }
}

int LinkedList::size(){
  int length = 0;

  std::shared_ptr<Node> current = head;
  while(current != nullptr){
    ++length;
    current = current->next;
  }
  return length;
}

std::shared_ptr<Tile> LinkedList::get(int index){
    std::shared_ptr<Tile> retTile = nullptr;

  if(index >= 0 && index < size()){

    int counter = 0;
      std::shared_ptr<Node> current = head;

    while(counter<index){

      ++counter;
      current = current->next;
    }

    retTile = current->tile;

  }

  return retTile;

}

void LinkedList::addFront(std::shared_ptr<Tile> data){
  std::shared_ptr<Node> node = std::make_shared<Node>();
  node->tile = data;
  node->next = head;
  head = node;

}

void LinkedList::addBack(std::shared_ptr<Tile> data){
  std::shared_ptr<Node> node = std::make_shared<Node>();
  node->tile = data;
  node->next = nullptr;

  if(head == nullptr){
    head = node;
  }else{
    std::shared_ptr<Node> current = head;
    while(current->next != nullptr){
        current = current->next;
    }
    current->next = node;
  }

}

std::shared_ptr<Tile> LinkedList::removeFront(){
	std::shared_ptr<Tile> removedTile;
    if(head != nullptr){
		removedTile = head->tile;
    	head = head->next;
    }else{
        throw std::runtime_error("Nothing to remove");
    }

    return removedTile;
}
void LinkedList::removeBack(){
    
    if(head != nullptr){
        std::shared_ptr<Node> current = head;

        std::shared_ptr<Node> prev = nullptr;

        while(current->next != nullptr){
            prev = current;
            current = current->next;
        }

        if(prev == nullptr){
            head = nullptr;
        }else{
            prev->next = nullptr;
        }

    }
    
}

void LinkedList::removeIndex(int index){
    if(index >= 0 && index < size()){
        if(head != nullptr){
            int counter = 0;
            std::shared_ptr<Node> current = head;
            std::shared_ptr<Node> prev = nullptr;

            while(counter != index){
                ++counter;
                prev = current;
                current = current->next;
            }

            if(prev == nullptr){
                head = current->next;
            }else{
                prev->next = current->next;
            }


        }
    }
}


int LinkedList::checkTile(string inputTile){
  int tileIndex = -1;
  
  if(head != nullptr){
    int index = 0;
    std::shared_ptr<Node> current = head;
    std::shared_ptr<Node> prev = nullptr;

    while(index != size()){
      if(current->tile->colour + std::to_string(current->tile->shape) == inputTile){
        tileIndex = index;
      }

      ++index;
      prev = current;
      current = current->next;
    }
  }

  return tileIndex;
}

void LinkedList::clear(){
  head = nullptr;
}

