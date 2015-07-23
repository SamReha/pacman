#include <SFML/Graphics.hpp>

// Tiles are the individual elements which make up a map.
class Tile {
private:
  enum type {HALL, WALL, WAYPOINT, SPC_WAYPOINT};
  
  type tileType;
  
  sf::Vector2<int> position;
  sf::Sprite sprite;
public:
  Tile(sf::Vector2<int> pos, sf::Sprite spr, type typeOfTile);
  
  sf::Vector2<int> getPosition();         // Gets the the position of the tile relative to the map
  sf::Sprite getSprite();                 // Fetches the sf::Sprite associated with this paddle
};