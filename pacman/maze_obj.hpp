// Heads up, you should probably never instantiate a maze_obj!
#include <SFML/Graphics.hpp>

#pragma once

class Maze_obj {
protected:
  sf::Sprite sprite;
  sf::Vector2<double> position;
public:
  sf::Sprite getSprite();
  sf::Vector2<double> getPosition();
  void setPosition(double, double);
  void setSprite(sf::Sprite spr);
};