#include "maze_obj.hpp"

class Pellet: public Maze_obj {
public:
  Pellet(sf::Sprite, sf::Vector2<double>);
  Pellet(sf::Sprite, double, double);
};