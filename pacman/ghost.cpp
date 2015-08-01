#include <iostream>
#include "ghost.hpp"

Ghost::Ghost(sf::Vector2<double> pos, sf::String ste) {
  position = pos;
  state = ste;
}

sf::String Ghost::getState() {
  return state;
}

void Ghost::update() {
  std::cout << "This ghost does not have an implemented update routine!";
}