# include "tile.hpp"

PacTile::PacTile(sf::Sprite spr, sf::String typeOfTile){
  sprite = spr;
  tileType = typeOfTile;
}

PacTile::PacTile(int unused) {
  sprite = sf::Sprite();
  tileType = sf::String("");
}

// Private

// Public
sf::Sprite PacTile::getSprite() {
  return sprite;
}

sf::String PacTile::getType() {
  return tileType;
}