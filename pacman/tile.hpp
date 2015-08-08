#include <SFML/Graphics.hpp>

#pragma once

// Tiles are the individual elements which make up a map.
class PacTile {
private:
  sf::Sprite sprite;
  sf::String tileType;
public:
  PacTile(sf::Sprite spr, sf::String typeOfTile);

  sf::Sprite getSprite();                 // Fetches the sf::Sprite associated with this tile
  sf::String getType();
};