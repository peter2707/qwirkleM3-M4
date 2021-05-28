
#include "Tile.h"

Tile::Tile(const Tile &tile){
    this->col = tile.col;
    this->row = tile.row;
    this->colour = tile.colour;
    this->shape = tile.shape;
}

Tile::Tile(Colour colour, Shape shape, Row row, Col col){
    this->col = col;
    this->row = row;
    this->colour = colour;
    this->shape = shape;
}

Tile::Tile(Colour colour, Shape shape){
    this->colour = colour;
    this->shape = shape;
}

Tile::~Tile(){
}

std::string Tile::getTile(){
    return this->colour + std::to_string(this->shape);
}

void Tile::setPosition(Row row, Col col){
    this->col = col;
    this->row = row;
}

