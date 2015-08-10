#include "map.hpp"

Map::Map(sf::Vector2<double> anchor, sf::Vector2<int> sze, int width) {
  anchorPoint = anchor;
  size = sze;
  tileWidth = width;
  
  mapBody = new PacTile* [size.x*size.y];
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
void Map::setTile(sf::Vector2<int> indexes, sf::Sprite spr, sf::String typeOfTile) {
  PacTile* tempTile = new PacTile(spr, typeOfTile);
  int realIndex = indexes.y*size.x + indexes.x;
  mapBody[realIndex] = tempTile;
}

void Map::setTile(sf::Vector2<int> indexes, PacTile* tile) {
  // Since we are smashing a 2D array into a 1D array, the real index is the number of rows down (The y pos * the row width) plus how many columns over (the x pos)
  int realIndex = indexes.y*size.x + indexes.x;
  mapBody[realIndex] = tile;
}

PacTile* Map::getTileAtIndex(sf::Vector2<int> pos) {
  int realIndex = pos.y*size.x + pos.x;
  return mapBody[realIndex];
}

PacTile* Map::getTileAtPoint(sf::Vector2<double> point) {
  int realIndex = getIndexFromPoint(point);
  return mapBody[realIndex];
}

sf::Vector2<int> Map::convertPositionToIndex(double x, double y) {
  int realIndex = getIndexFromPoint(sf::Vector2<double>(x, y));
  int xComponent = realIndex%size.x;
  int yComponent = realIndex/size.x;
  
  return sf::Vector2<int>(xComponent, yComponent);
}

sf::Vector2<int> Map::getSize() {
  return size;
}

sf::Vector2<double> Map::getAnchor() {
  return anchorPoint;
}

int Map::getTileWidth() {
  return tileWidth;
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