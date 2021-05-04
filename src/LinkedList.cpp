
#include "LinkedList.h"
#include <stdexcept>

LinkedList::LinkedList() {
   head = nullptr;
}


LinkedList::~LinkedList() {
  clear();
}

LinkedList::LinkedList(LinkedList& other){
  head = nullptr;
  for(int i = 0; i < other.size(); ++i){
    Tile* tile = new Tile(*other.get(i));
    addBack(tile);
  }
}

int LinkedList::size(){
  int length = 0;

  Node* current = head;
  while(current != nullptr){
    ++length;
    current = current->next;
  }
  return length;
}

Tile* LinkedList::get(int index){
  Tile* retTile = nullptr;

  if(index >= 0 && index < size()){

    int counter = 0;
    Node* current = head;

    while(counter<index){

      ++counter;
      current = current->next;
    }

    retTile = current->tile;

  }

  return retTile;

}

void LinkedList::addFront(Tile* data){

Node* node = new Node(data, head);
head = node;

}

void LinkedList::addBack(Tile* data){
  Node* node = new Node(data, head);
  node->tile = data;
  node->next = nullptr;

  if(head == nullptr){
    head = node;
  }else{
    Node* current = head;
    while(current->next != nullptr){
        current = current->next;
    }
    current->next = node;
  }

}

void LinkedList::removeFront(){
    if(head != nullptr){
        Node* toDelete = head;
        head = head->next;

        delete toDelete->tile;
        delete toDelete;
    }else{
        throw std::runtime_error("Nothing to remove");
    }

}
void LinkedList::removeBack(){
    
    if(head != nullptr){
        Node* current = head;

        Node* prev = nullptr;

        while(current->next != nullptr){
            prev = current;
            current = current->next;
        }

        if(prev == nullptr){
            head = nullptr;
        }else{
            prev->next = nullptr;
        }

        delete current->tile;
        delete current;
    }
    
}

void LinkedList::removeIndex(int index){
    if(index >= 0 && index < size()){
        if(head != nullptr){
            int counter = 0;
            Node* current = head;
            Node* prev = nullptr;

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

            delete current->tile;
            delete current;
        }
    }
}

void LinkedList::clear(){
    while(head != nullptr){
        removeFront();
    }
}

