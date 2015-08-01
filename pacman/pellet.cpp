# include "pellet.hpp"

Pellet::Pellet(sf::Sprite spr, sf::Vector2<double> pos) {
  sprite = spr;
  position = pos;
}

Pellet::Pellet(sf::Sprite spr, double x, double y) {
  sprite = spr;
  position = sf::Vector2<double>(x, y);
}