#include <iostream>

#include "character.hpp"

// Private

// Public
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

void Character::setVelocity(sf::Vector2<double> newVelocity) {
  velocity = newVelocity;
}

void Character::setDirection(sf::String newDir) {
  moveDir = newDir;
}

sf::Vector2<double> Character::getVelocity() {
  return velocity;
}

double Character::getXVel() {
  return velocity.x;
}

double Character::getYVel() {
  return velocity.y;
}

sf::String Character::getDirection() {
  return moveDir;
}

void Character::update() {
  std::cout << "This character does not have an implemented update routine!";
}