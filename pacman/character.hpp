#include "maze_obj.hpp"

#pragma once

class Character: public Maze_obj {
protected:
  std::vector<sf::Sprite> upSprites;
  std::vector<sf::Sprite> downSprites;
  std::vector<sf::Sprite> leftSprites;
  std::vector<sf::Sprite> rightSprites;
  
  sf::Vector2<double> velocity;
public:
  Character(sf::Vector2<double> pos);

  void setUpSprites(std::vector<sf::Sprite>);
  void setDownSprites(std::vector<sf::Sprite>);
  void setLeftSprites(std::vector<sf::Sprite>);
  void setRightSprites(std::vector<sf::Sprite>);
  
  void update();
};