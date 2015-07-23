#include <SFML/Graphics.hpp>
enum type {HALL, WALL, WAYPOINT, SPC_WAYPOINT};

// Tiles are the individual elements which make up a map.
class Tile {
private:
  sf::Vector2<int> position;
  sf::Sprite sprite;
public:
  type tileType;
  Tile(sf::Vector2<int> pos, sf::Sprite spr, type typeOfTile);
  
  sf::Vector2<int> getPosition();         // Gets the the position of the tile relative to the map
  sf::Sprite getSprite();                 // Fetches the sf::Sprite associated with this paddle
  type getType();
};