
#include "LinkedList.h"

LinkedList::LinkedList() {
   head = nullptr;

   // TODO
}

LinkedList::~LinkedList() {
}

std::shared_ptr<Tile> LinkedList::removeFront(){
   if(head != nullptr){
      head = head->next;
   }
}

void LinkedList::addBack(std::shared_ptr<Tile> data){
   std::shared_ptr<Node> node = std::make_shared<Node>();
   node->tile = data;
   node->next = nullptr;

   if(head == nullptr){
      head = node;
   } else {
      std::shared_ptr<Node> current = head;
      while(current->next != nullptr){
         current = current->next;
      }
      current->next = node;
   }
}