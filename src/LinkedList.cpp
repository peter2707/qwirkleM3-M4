
#include "LinkedList.h"

LinkedList::LinkedList() {
   head = nullptr;
   tail = nullptr;
   
}

LinkedList::~LinkedList() {
}

void LinkedList::removeFront() {
  if (head != nullptr) {
    Node* temp = head;
    head = temp->next;
    delete temp;
  }
}

void LinkedList::removeBack() {
  Node* temp = head;
  Node* prev = nullptr;
  while (temp->next != nullptr) {
    prev = temp;
    temp = temp->next;
  }
  prev->next = nullptr;
  tail = prev;
  delete temp;
}

void LinkedList::addTile(Tile* tile) {
  Node* node = new Node(tile, nullptr);
  if (tail != nullptr) {
    tail->next = node;
    tail = node;
  } else {
    head = node;
    tail = node;
  }
}
