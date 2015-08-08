//#include <SFML/Graphics.hpp>
#include <iostream>

#include "character.hpp"

#pragma once

class Ghost: public Character {
protected:
  std::vector<sf::Sprite> blueSprites;
  std::vector<sf::Sprite> whiteSprites;
  sf::Sprite ghostEyesUp;
  sf::Sprite ghostEyesDown;
  sf::Sprite ghostEyesLeft;
  sf::Sprite ghostEyesRight;

  sf::String state;
public:
  Ghost(sf::Vector2<double>, sf::String);

  void setBlueSprites(std::vector<sf::Sprite>);
  void setWhiteSprites(std::vector<sf::Sprite>);
  void setEyeBallSprites(std::vector<sf::Sprite>);
  
  sf::String getState();    // Fetches current state
  
  void update();
};