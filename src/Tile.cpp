
#include "Tile.h"

Tile::Tile(const Tile &tile)
{
    this->col = tile.col;
    this->row = tile.row;
    this->colour = tile.colour;
    this->shape = tile.shape;
}

Tile::Tile(Colour colour, Shape shape)
{
    this->colour = colour;
    this->shape = shape;
}

Tile::~Tile(){
    this->colour = ' ';
    this->shape = -1;
}

void Tile::setPosition(Row row, Col col)
{
    this->col = col;
    this->row = row;
}

bool Tile::empty(){
    return (this->colour == ' ' && this->shape==-1);
}
