#include "maze_obj.hpp"

#pragma once

class Character: public Maze_obj {
protected:
  std::vector<sf::Sprite> upSprites;
  std::vector<sf::Sprite> downSprites;
  std::vector<sf::Sprite> leftSprites;
  std::vector<sf::Sprite> rightSprites;
  
  sf::Vector2<double> velocity;
  sf::String moveDir;   // The current direction of movement
public:
  void setUpSprites(std::vector<sf::Sprite>);
  void setDownSprites(std::vector<sf::Sprite>);
  void setLeftSprites(std::vector<sf::Sprite>);
  void setRightSprites(std::vector<sf::Sprite>);
  void setVelocity(sf::Vector2<double> newVelocity);
  void setXVel(double newX);
  void setYVel(double newY);
  void setDirection(sf::String newDir);
  
  sf::Vector2<double> getVelocity();
  double getXVel();
  double getYVel();
  sf::String getDirection();
  
  void update();
};