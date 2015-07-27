#include <SFML/Graphics.hpp>

// Tiles are the individual elements which make up a map.
class PacTile {
private:
  sf::Vector2<int> position;
  sf::Sprite sprite;
  sf::String tileType;
public:
  PacTile(sf::Vector2<int> pos, sf::Sprite spr, sf::String typeOfTile);
  
  sf::Vector2<int> getPosition();         // Gets the the position of the tile relative to the map
  sf::Sprite getSprite();                 // Fetches the sf::Sprite associated with this paddle
  sf::String getType();
};