#include "map.hpp"
#include "tile.hpp"

Map::Map(sf::Vector2<double> anchor, sf::Vector2<int> sze, int width) {
  anchorPoint = anchor;
  size = sze;
  tileWidth = width;
  
  mapBody = new Tile* [size.x*size.y];
}

// Private

// Public
void Map::setTile(sf::Vector2<int> indexes, sf::Sprite spr, type typeOfTile) {
  Tile tempTile = new Tile(indexes, spr, typeOfTile);
}