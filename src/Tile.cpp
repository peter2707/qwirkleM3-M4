
#include "Tile.h"

Tile::Tile(Colour colour, Shape shape)
{
    this->colour = colour;
    this->shape = shape;
}

Tile::~Tile(){}

void Tile::setPosition(Row row, Col col)
{
    this->col = col;
    this->row = row;
}

