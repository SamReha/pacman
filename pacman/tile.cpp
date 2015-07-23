# include "tile.hpp"

Tile::Tile(sf::Vector2<int> pos, sf::Sprite spr, type typeOfTile){
  position = pos;
  sprite = spr;
  tileType = typeOfTile;
}

// Private

// Public
sf::Vector2<int> Tile::getPosition() {
  return position;
}

sf::Sprite Tile::getSprite() {
  return sprite;
}