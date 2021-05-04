
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:


   LinkedList();
   ~LinkedList();
   LinkedList(LinkedList& other);
   
   int size();

   Tile* get(int index);

   void addFront(Tile* data);
   void addBack(Tile* data);


   void removeFront();
   void removeBack();
   void removeIndex(int index);

   void clear();


private:
   Node* head;
};

#endif // ASSIGN2_LINKEDLIST_H
