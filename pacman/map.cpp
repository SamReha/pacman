#include "map.hpp"
#include "tile.hpp"

Map::Map(sf::Vector2<double> anchor, sf::Vector2<int> sze, int width) {
  anchorPoint = anchor;
  size = sze;
  tileWidth = width;
  
  mapBody = new Tile* [size.x*size.y];
}

// Private
// Compute index from point (in pixels), anchorPoint, and tileWidth
int Map::getIndexFromPoint(sf::Vector2<double> point) {
  sf::Vector2<double> tempCoord = sf::Vector2<double>(point.x, point.y);
  
  // Normalize the coordinate to our map's origin
  tempCoord.x = point.x - anchorPoint.x;
  tempCoord.y = point.y - anchorPoint.y;
  
  // Normalize the coordinate to our map's tile width
  tempCoord.x = tempCoord.x/tileWidth;
  tempCoord.y = tempCoord.y/tileWidth;
  
  // Normalize the entire coordinate into a 1D index
  return tempCoord.y*size.x + tempCoord.x;
}

// Public
void Map::setTile(sf::Vector2<int> indexes, sf::Sprite spr, type typeOfTile) {
  Tile* tempTile = new Tile(indexes, spr, typeOfTile);
  int realIndex = indexes.y*size.x + indexes.x;
  mapBody[realIndex] = tempTile;
}

void Map::setTile(sf::Vector2<int> indexes, Tile* tile) {
  // Since we are smashing a 2D array into a 1D array, the real index is the number of rows down (The y pos * the row width) plus how many columns over (the x pos)
  int realIndex = indexes.y*size.x + indexes.x;
  mapBody[realIndex] = tile;
}

Tile* Map::getTileAtIndex(sf::Vector2<int> pos) {
  int realIndex = pos.y*size.x + pos.x;
  return mapBody[realIndex];
}

Tile* Map::getTileAtPoint(sf::Vector2<double> point) {
  int realIndex = getIndexFromPoint(point);
  return mapBody[realIndex];
}

sf::Vector2<int> Map::getSize() {
  return size;
}

void Map::deleteTile(sf::Vector2<int> indexes) {
  int realIndex = indexes.y*size.x + indexes.x;
  delete mapBody[realIndex];
  mapBody[realIndex] = NULL;
}

void Map::deleteAllTiles() {
  for (int i = 0; i < size.x*size.y; i++) {
    if (mapBody[i] != NULL) {
      delete mapBody[i];
      mapBody[i] = NULL;
    }
  }
}