# include "tile.hpp"

PacTile::PacTile(sf::Vector2<int> pos, sf::Sprite spr, sf::String typeOfTile){
  position = pos;
  sprite = spr;
  tileType = typeOfTile;
}

// Private

// Public
sf::Vector2<int> PacTile::getPosition() {
  return position;
}

sf::Sprite PacTile::getSprite() {
  return sprite;
}

sf::String PacTile::getType() {
  return tileType;
}