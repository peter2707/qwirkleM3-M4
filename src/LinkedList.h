
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"
#include <iostream>

class LinkedList {
public:

   LinkedList();
   ~LinkedList();
   std::shared_ptr<Tile> removeFront();
   void addBack(std::shared_ptr<Tile> data);

private:
   std::shared_ptr<Node> head;
};

#endif // ASSIGN2_LINKEDLIST_H
