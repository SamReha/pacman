# include "tile.hpp"

PacTile::PacTile(sf::Sprite spr, sf::String typeOfTile){
  sprite = spr;
  tileType = typeOfTile;
}

// Private

// Public
sf::Sprite PacTile::getSprite() {
  return sprite;
}

sf::String PacTile::getType() {
  return tileType;
}