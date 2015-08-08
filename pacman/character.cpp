#include <iostream>

#include "character.hpp"

// Private

// Public
Character::Character(sf::Vector2<double> pos) {
  position = pos;
}

void Character::setUpSprites(std::vector<sf::Sprite> vector) {
  upSprites = vector;
}

void Character::setDownSprites(std::vector<sf::Sprite> vector) {
  downSprites = vector;
}

void Character::setLeftSprites(std::vector<sf::Sprite> vector) {
  leftSprites = vector;
}

void Character::setRightSprites(std::vector<sf::Sprite> vector) {
  rightSprites = vector;
}

void Character::update() {
  std::cout << "This character does not have an implemented update routine!";
}