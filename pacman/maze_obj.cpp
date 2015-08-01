#include "maze_obj.hpp"

// Protected

// Public
sf::Sprite Maze_obj::getSprite() {
  return sprite;
}
sf::Vector2<double> Maze_obj::getPosition() {
  return position;
}
void Maze_obj::setPosition(double x, double y) {
  position = sf::Vector2<double>(x, y);
}
void Maze_obj::setSprite(sf::Sprite spr) {
  sprite = spr;
}