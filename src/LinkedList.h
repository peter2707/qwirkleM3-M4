
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:


   LinkedList();
   ~LinkedList();
   LinkedList(LinkedList& other);
   
   int size();

    std::shared_ptr<Tile> get(int index);

   void addFront(std::shared_ptr<Tile> data);
   void addBack(std::shared_ptr<Tile> data);


   std::shared_ptr<Tile> removeFront();
   void removeBack();
   void removeIndex(int index);

   void clear();


private:
    std::shared_ptr<Node> head;
};

#endif // ASSIGN2_LINKEDLIST_H
