#include "tile.hpp"

class Map {
private:
  Tile** mapBody;
  sf::Vector2<int> size;
  sf::Vector2<double>anchorPoint;
  int tileWidth;
  
  int getIndexFromPoint(sf::Vector2<double> point);
public:
  Map(sf::Vector2<double> anchor, sf::Vector2<int> sze, int width);
  
  void setTile(sf::Vector2<int> indexes, sf::Sprite spr, type typeOfTile); // Set a tile by index
  void setTile(sf::Vector2<int> indexes, Tile* tile);
  
  Tile* getTileAtIndex(sf::Vector2<int> pos);                              // Gets tile by array index
  Tile* getTileAtPoint(sf::Vector2<double> point);                         // Gets tile by position on screen
  sf::Vector2<int> getSize();                                           // Gets size as a vector
  
  void deleteTile(sf::Vector2<int> indexes);                               // Delets tile at given (x, y) index
  void deleteAllTiles();                                                   // Deletes all tiles
};