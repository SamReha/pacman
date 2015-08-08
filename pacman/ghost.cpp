#include "ghost.hpp"

Ghost::Ghost(sf::Vector2<double> pos, sf::String ste) {
  position = pos;
  state = ste;
}

void Ghost::setUpSprites(std::vector<sf::Sprite> vector) {
  upSprites = vector;
}

void Ghost::setDownSprites(std::vector<sf::Sprite> vector) {
  downSprites = vector;
}

void Ghost::setLeftSprites(std::vector<sf::Sprite> vector) {
  leftSprites = vector;
}

void Ghost::setRightSprites(std::vector<sf::Sprite> vector) {
  rightSprites = vector;
}

void Ghost::setBlueSprites(std::vector<sf::Sprite> vector) {
  blueSprites = vector;
}

void Ghost::setWhiteSprites(std::vector<sf::Sprite> vector) {
  whiteSprites = vector;
}

void Ghost::setEyeBallSprites(std::vector<sf::Sprite> vector) {
  ghostEyesUp = vector[0];
  ghostEyesDown = vector[1];
  ghostEyesLeft = vector[2];
  ghostEyesRight = vector[3];
}

sf::String Ghost::getState() {
  return state;
}

void Ghost::update() {
  std::cout << "This ghost does not have an implemented update routine!";
}