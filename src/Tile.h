#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

#include "Type.h"

class Tile {
public:
   
   Tile(Colour colour, Shape shape);
   ~Tile();

   Colour colour;
   Shape  shape;
   
   Row row;
   Col col;
};

#endif // ASSIGN2_TILE_H
