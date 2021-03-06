#include "tile.hpp"

#pragma once

class Map {
private:
  PacTile** mapBody;
  sf::Vector2<int> size;
  sf::Vector2<double>anchorPoint;
  int tileWidth;
  
  int getIndexFromPoint(sf::Vector2<double> point);
public:
  Map(sf::Vector2<double> anchor, sf::Vector2<int> sze, int width);
  
  void setTile(sf::Vector2<int> indexes, sf::Sprite spr, sf::String typeOfTile); // Set a tile by index
  void setTile(sf::Vector2<int> indexes, PacTile* tile);
  
  PacTile* getTileAtIndex(sf::Vector2<int> pos);                        // Gets tile by array index
  PacTile* getTileAtPoint(sf::Vector2<double> point);                   // Gets tile by position on screen
  sf::Vector2<int> convertPositionToIndex(double x, double y);
  sf::Vector2<int> getSize();                                           // Gets size as a vector
  sf::Vector2<double> getAnchor();
  int getTileWidth();
  
  void configureMap(std::map<sf::String, PacTile*> tileSet);           // Sets up the tiles for the map
  
  void deleteTile(sf::Vector2<int> indexes);                            // Delets tile at given (x, y) index
  void deleteAllTiles();                                                // Deletes all tiles
};