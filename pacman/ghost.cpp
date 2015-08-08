#include "ghost.hpp"

Ghost::Ghost(sf::Vector2<double> pos, sf::String ste) {
  position = pos;
  state = ste;
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